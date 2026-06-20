__int64 __fastcall sub_2BB41C(__int64 a1)
{
  int v1; // w13

  if ( (v1 & 0x1000000) != 0 )
    JUMPOUT(0x2BD198);
  return cam_presil_unsubscribe_device_irq(a1);
}
