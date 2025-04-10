
# 🎛️ Gesture to Sound Mapping – AirNote

This document describes how physical gestures are mapped to musical outputs using sensors.

## 🤲 Flex Sensor Mapping
| Finger Bend (Flex1) | Action           |
|---------------------|------------------|
| Low (straight)      | Lower pitch (C4) |
| Medium              | Mid pitch (D, E) |
| High (bent)         | Higher pitch (C5)|

| Hand Grip (Flex2)   | Duration         |
|---------------------|------------------|
| Loose               | Short note       |
| Firm grip           | Long sustained   |

## 🌀 MPU6050 Mapping (Future Enhancements)
| Gesture             | Mode/Effect          |
|---------------------|----------------------|
| Tilt left/right     | Octave shift         |
| Tilt forward/back   | Vibrato/Modulation   |
| Shake               | Percussion trigger   |
