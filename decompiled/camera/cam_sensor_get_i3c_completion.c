char *__fastcall cam_sensor_get_i3c_completion(unsigned int a1)
{
  if ( a1 < 0x10 )
    return (char *)&g_i3c_sensor_data + 40 * a1 + 8;
  __break(0x5512u);
  return (char *)cam_sensor_i2c_driver_remove();
}
