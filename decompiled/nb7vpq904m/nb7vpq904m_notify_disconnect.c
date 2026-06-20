__int64 __fastcall nb7vpq904m_notify_disconnect(__int64 a1)
{
  __int64 v2; // x0

  if ( *(_DWORD *)(a1 + 124) )
  {
    v2 = *(_QWORD *)(a1 + 96);
    *(_DWORD *)(a1 + 124) = 0;
    if ( (regmap_write(v2, 0, 0) & 0x80000000) != 0 )
    {
      dev_err(*(_QWORD *)(a1 + 88), "writing reg 0x%02x failure\n", 0);
    }
    else if ( *(_QWORD *)(a1 + 112) && *(_BYTE *)(a1 + 166) == 1 )
    {
      *(_BYTE *)(a1 + 166) = 0;
      regulator_disable();
      regulator_set_voltage(*(_QWORD *)(a1 + 112), 0, 1890000);
      regulator_set_load(*(_QWORD *)(a1 + 112), 0);
    }
  }
  return 0;
}
