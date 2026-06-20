__int64 __usercall sub_12D80@<X0>(int a1@<W8>)
{
  if ( !a1 )
    JUMPOUT(0x865BC);
  return cnss_bus_set_therm_cdev_state();
}
