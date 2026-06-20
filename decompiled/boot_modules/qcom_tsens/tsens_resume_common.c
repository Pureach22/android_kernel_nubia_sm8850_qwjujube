__int64 __fastcall tsens_resume_common(_QWORD *a1)
{
  __int64 v1; // x8
  unsigned int v3; // w20

  if ( pm_suspend_target_state == 3 )
  {
    v1 = a1[318];
    if ( *(_DWORD *)v1 >= 3u )
    {
      v3 = 7;
      if ( (*(_BYTE *)(v1 + 4) & 0x10) != 0 )
      {
        regmap_field_update_bits_base(a1[273], 0xFFFFFFFFLL, 0, 0, 0, 0);
        regmap_field_update_bits_base(a1[277], 0xFFFFFFFFLL, 1, 0, 0, 0);
        if ( *(_DWORD *)a1[318] <= 2u )
          v3 = 1;
        else
          v3 = 7;
      }
      if ( (regmap_field_update_bits_base(a1[14], 0xFFFFFFFFLL, v3, 0, 0, 0) & 0x80000000) != 0 )
        dev_err(*a1, "%s: failed to enable interrupts\n", "tsens_enable_irq");
    }
  }
  return 0;
}
