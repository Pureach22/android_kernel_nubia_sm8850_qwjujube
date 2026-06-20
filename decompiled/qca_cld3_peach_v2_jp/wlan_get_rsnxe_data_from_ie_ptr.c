unsigned __int8 *__fastcall wlan_get_rsnxe_data_from_ie_ptr(unsigned __int8 *a1, unsigned __int16 a2)
{
  char is_rsn_override_present; // w0
  char v5; // w21
  int v6; // w24
  unsigned __int8 *v7; // x25
  __int64 v8; // x26
  unsigned int v9; // w8
  unsigned __int8 *result; // x0
  int v11; // w8
  __int64 v12; // x9
  unsigned int v13; // w8
  bool v14; // cf

  is_rsn_override_present = wlan_is_rsn_override_present();
  if ( (a2 & 0xFFFE) != 0 )
  {
    v5 = is_rsn_override_present;
    v6 = a2;
    v7 = a1;
    while ( 1 )
    {
      v8 = v7[1];
      v9 = v6 - 2;
      v6 = v6 - 2 - v8;
      if ( v9 < (unsigned int)v8 )
      {
LABEL_14:
        if ( (a2 & 0xFFFE) == 0 )
          return nullptr;
        goto LABEL_15;
      }
      if ( *v7 == 221 )
      {
        if ( v9 < 4 )
          goto LABEL_14;
        if ( !(unsigned int)qdf_mem_cmp(v7 + 2, &unk_99A16C, 4u) )
          break;
      }
      v7 += v8 + 2;
      if ( v6 <= 1 )
        goto LABEL_14;
    }
    if ( v7 != nullptr && v5 != 0 )
      result = v7;
    else
      result = nullptr;
    if ( v7 != nullptr && v5 != 0 || (a2 & 0xFFFE) == 0 )
      return result;
LABEL_15:
    v11 = a2;
    do
    {
      v12 = a1[1];
      v13 = v11 - 2;
      v14 = v13 >= (unsigned int)v12;
      v11 = v13 - v12;
      if ( !v14 )
        break;
      if ( *a1 == 244 )
        return a1;
      a1 += v12 + 2;
    }
    while ( v11 > 1 );
  }
  return nullptr;
}
