//
//  ViewController.swift
//  SpeedUp
//
//  Created by SAMEER SURESH on 10/10/15.
//  Copyright (c) 2015 SAMEER SURESH. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var nrfManager:NRFManager!
    var mapCircle: NMAMapCircle?
    
    @IBOutlet weak var mapView: NMAMapView!
    @IBOutlet weak var BluetoothSuccess: UILabel!
    @IBAction func testbtn(sender: AnyObject) {
        var timeinput = Textfield.text
//        let connectionstatus = "Connection successful"
        self.sendData()
    }

    @IBOutlet weak var Textfield: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        nrfManager = NRFManager(
            onConnect: {
                print("Connected")
            },
            onDisconnect: {
                print("Disconnected")
            },
            onData: {
                (data:NSData?, string:String?)->() in
                print("Received data - String: \(string) - Data: \(data)")
            },
            autoConnect: false
            
        )
        nrfManager.connect()
//        var connectionstatus = nrfManager.connectionMode
//        var stringified = String(connectionstatus)
//        self.BluetoothSuccess.text = ConnectionStatus
        print(nrfManager.connectionMode)
        
    }
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        mapView.useHighResolutionMap = true
        var coordinates: NMAGeoCoordinates
        coordinates = NMAGeoCoordinates(latitude: 37.8717, longitude: -122.2728)
        mapView.zoomLevel = 13.2
        mapView.setGeoCenter(coordinates, withAnimation: NMAMapAnimation.Linear)
        mapView.copyrightLogoPosition = NMALayoutPosition.BottomCenter
        addMapCircle()
    }
    
    func addMapCircle() {
        if mapCircle == nil {
            let coordinates: NMAGeoCoordinates =
            NMAGeoCoordinates(latitude: 49.258867, longitude: -123.008046)
            mapCircle = NMAMapCircle(geoCoordinates: coordinates, radius: 50)
            mapView.addMapObject(mapCircle)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func sendData(){
        let result = self.nrfManager.writeString("6")
        print(result)
        
    }
    
    


}

