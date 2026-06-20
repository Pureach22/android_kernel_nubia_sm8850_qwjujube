bool __fastcall policy_mgr_get_index_for_4sap_dbs(int *a1, unsigned int *a2)
{
  unsigned int *v3; // x20
  _BOOL4 is_24ghz_ch_freq; // w22
  _BOOL4 v5; // w23
  bool v6; // w0
  int v7; // w22
  int v8; // w23
  bool v9; // w0
  unsigned int v10; // w8
  _BOOL8 result; // x0
  int v12; // w8
  int v13; // w9
  int v14; // w8

  v3 = a2;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*a2);
  v5 = !is_24ghz_ch_freq;
  v6 = wlan_reg_is_24ghz_ch_freq(v3[1]);
  v7 = is_24ghz_ch_freq + v6;
  v8 = v5 + !v6;
  v9 = wlan_reg_is_24ghz_ch_freq(v3[2]);
  v10 = v3[3];
  LODWORD(v3) = v9;
  result = wlan_reg_is_24ghz_ch_freq(v10);
  v12 = v7 + (_DWORD)v3 + result;
  v13 = v8 + ((_DWORD)v3 == 0) + !result;
  if ( v12 == 2 && v13 == 2 )
  {
    v14 = 3;
LABEL_10:
    *a1 = v14;
    return result;
  }
  if ( v12 == 1 && v13 == 3 )
  {
    v14 = 5;
    goto LABEL_10;
  }
  if ( v12 == 3 && v13 == 1 )
  {
    v14 = 4;
    goto LABEL_10;
  }
  return result;
}
