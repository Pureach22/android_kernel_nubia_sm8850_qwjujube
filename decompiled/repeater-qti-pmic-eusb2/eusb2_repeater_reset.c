__int64 __fastcall eusb2_repeater_reset(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x3
  int updated; // w0

  v3 = *(_QWORD *)(a1 + 88);
  if ( (a2 & 1) != 0 )
    v4 = 128;
  else
    v4 = 0;
  updated = regmap_update_bits_base(v3, (unsigned int)*(unsigned __int16 *)(a1 + 96) + 70, 128, v4, 0, 0, 0);
  if ( updated )
    dev_err(*(_QWORD *)a1, "write failed: addr=0x%04x, ret=%d\n", *(unsigned __int16 *)(a1 + 96) + 70, updated);
  return 0;
}
