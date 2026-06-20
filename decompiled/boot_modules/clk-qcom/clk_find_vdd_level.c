__int64 __fastcall clk_find_vdd_level(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x13

  v3 = *(unsigned int *)(a2 + 24);
  if ( !(_DWORD)v3 )
    return 4294967235LL;
  if ( (int)v3 < 1 )
  {
    LODWORD(v4) = 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8 * v4);
      if ( v5 )
      {
        if ( (a3 + 500) / 0x3E8uLL <= (v5 + 500) / 0x3E8uLL )
          break;
      }
      if ( v3 == ++v4 )
        goto LABEL_12;
    }
  }
  if ( (_DWORD)v4 == (_DWORD)v3 )
  {
LABEL_12:
    clk_hw_get_name(a1);
    printk(&unk_28C46);
    LODWORD(v4) = -22;
  }
  return (unsigned int)v4;
}
