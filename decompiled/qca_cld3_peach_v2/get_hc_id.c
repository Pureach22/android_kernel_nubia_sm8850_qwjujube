__int64 __fastcall get_hc_id(__int64 a1, unsigned __int8 a2, unsigned int *a3)
{
  __int64 v4; // x21
  int v5; // w23
  unsigned int _5g_low_high_cut_freq; // w20
  bool is_24ghz_ch_freq; // w0
  _BYTE *v8; // x8
  __int64 v9; // x8
  __int64 result; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  LOBYTE(v4) = a2;
  v5 = a2;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  _5g_low_high_cut_freq = policy_mgr_get_5g_low_high_cut_freq(a1);
  qdf_mem_set(&v11, 4u, 0);
  if ( v5 )
  {
    v4 = (unsigned __int8)v4;
    do
    {
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*a3);
      v8 = (char *)&v11 + 1;
      if ( !is_24ghz_ch_freq )
      {
        if ( *a3 <= _5g_low_high_cut_freq )
          v9 = 2;
        else
          v9 = 3;
        v8 = (_BYTE *)((unsigned __int64)&v11 | v9);
      }
      --v4;
      ++a3;
      ++*v8;
    }
    while ( v4 );
  }
  result = *(unsigned __int16 *)((char *)&v11 + 1) | (HIBYTE(v11) << 16);
  if ( (int)result < 0x10000 )
  {
    if ( (int)result > 256 )
    {
      if ( (int)result > 512 )
      {
        if ( (_DWORD)result == 513 )
        {
          result = 11;
          goto LABEL_49;
        }
        if ( (_DWORD)result == 768 )
        {
          result = 15;
          goto LABEL_49;
        }
      }
      else
      {
        if ( (_DWORD)result == 257 )
        {
          result = 7;
          goto LABEL_49;
        }
        if ( (_DWORD)result == 512 )
        {
          result = 6;
          goto LABEL_49;
        }
      }
    }
    else if ( (int)result > 1 )
    {
      if ( (_DWORD)result == 2 )
      {
        result = 9;
        goto LABEL_49;
      }
      if ( (_DWORD)result == 256 )
      {
        result = 2;
        goto LABEL_49;
      }
    }
    else if ( (unsigned int)result < 2 )
    {
      goto LABEL_49;
    }
LABEL_48:
    result = 17;
    goto LABEL_49;
  }
  if ( (int)result <= 66047 )
  {
    if ( (int)result > 65791 )
    {
      if ( (_DWORD)result == 65792 )
      {
        result = 4;
        goto LABEL_49;
      }
      if ( (_DWORD)result == 65793 )
      {
        result = 10;
        goto LABEL_49;
      }
    }
    else
    {
      if ( (_DWORD)result == 0x10000 )
      {
        result = 3;
        goto LABEL_49;
      }
      if ( (_DWORD)result == 65537 )
      {
        result = 8;
        goto LABEL_49;
      }
    }
    goto LABEL_48;
  }
  if ( (int)result <= 0x20000 )
  {
    if ( (_DWORD)result == 66048 )
    {
      result = 13;
      goto LABEL_49;
    }
    if ( (_DWORD)result == 0x20000 )
    {
      result = 5;
      goto LABEL_49;
    }
    goto LABEL_48;
  }
  if ( (_DWORD)result == 131073 )
  {
    result = 12;
    goto LABEL_49;
  }
  if ( (_DWORD)result == 131328 )
  {
    result = 14;
    goto LABEL_49;
  }
  if ( (_DWORD)result != 196608 )
    goto LABEL_48;
  result = 16;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
