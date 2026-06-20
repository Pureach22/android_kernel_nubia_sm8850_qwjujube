__int64 __fastcall sde_hw_intf_enable_compressed_input(__int64 result, char a2, char a3)
{
  __int64 v5; // x19
  unsigned int v6; // w0
  unsigned int v7; // w8
  __int64 v8; // x2

  if ( result )
  {
    v5 = result;
    v6 = sde_reg_read(result, 96);
    v7 = **(_DWORD **)(v5 + 48) >> 28;
    if ( v7 >= 7 && (a2 & 1) != 0 || v7 == 6 && (a3 & 1) != 0 )
    {
      v8 = v6 | 0x1000;
    }
    else if ( (a2 & 1) != 0 )
    {
      v8 = v6;
    }
    else
    {
      v8 = v6 & 0xFFFFEFFF;
    }
    return sde_reg_write(v5, 96, v8, "INTF_CONFIG2");
  }
  return result;
}
