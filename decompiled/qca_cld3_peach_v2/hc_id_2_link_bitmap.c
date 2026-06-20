void *__fastcall hc_id_2_link_bitmap(__int64 a1, unsigned __int8 a2, unsigned int *a3, char *a4, int a5, int *a6)
{
  __int64 v8; // x24
  int v10; // w19
  unsigned int _5g_low_high_cut_freq; // w23
  void *result; // x0
  char v13; // t1
  char *v14; // x8
  __int64 v15; // x8
  int v16; // w8
  int v17; // w8
  int v18; // w9
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  LOBYTE(v8) = a2;
  v10 = a2;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  _5g_low_high_cut_freq = policy_mgr_get_5g_low_high_cut_freq(a1);
  result = qdf_mem_set(&v20, 0x10u, 0);
  if ( v10 )
  {
    v8 = (unsigned __int8)v8;
    do
    {
      result = (void *)wlan_reg_is_24ghz_ch_freq(*a3);
      v14 = (char *)&v20 + 4;
      if ( ((unsigned __int8)result & 1) == 0 )
      {
        if ( *a3 <= _5g_low_high_cut_freq )
          v15 = 8;
        else
          v15 = 12;
        v14 = (char *)&v20 + v15;
      }
      v13 = *a4++;
      --v8;
      ++a3;
      *(_DWORD *)v14 |= 1 << v13;
    }
    while ( v8 );
  }
  switch ( a5 )
  {
    case 1:
      v16 = HIDWORD(v20);
      goto LABEL_17;
    case 2:
    case 6:
    case 15:
      v16 = v21;
      goto LABEL_17;
    case 3:
    case 5:
    case 16:
      v16 = HIDWORD(v21);
      goto LABEL_17;
    case 4:
    case 13:
    case 14:
      v17 = v21;
      goto LABEL_15;
    case 7:
    case 11:
      v17 = HIDWORD(v20);
      v18 = v21;
      goto LABEL_16;
    case 8:
    case 12:
      v17 = HIDWORD(v20);
LABEL_15:
      v18 = HIDWORD(v21);
LABEL_16:
      v16 = v18 | v17;
      goto LABEL_17;
    case 10:
      v16 = v21 | HIDWORD(v20) | HIDWORD(v21);
LABEL_17:
      *a6 = v16;
      break;
    default:
      break;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
