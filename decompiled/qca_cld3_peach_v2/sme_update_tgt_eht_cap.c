void *__fastcall sme_update_tgt_eht_cap(_QWORD *a1, _BYTE *a2)
{
  __int64 v4; // x0
  unsigned int v5; // w9
  _DWORD *v6; // x12
  unsigned int v7; // w8
  int v8; // w10
  __int64 v9; // x0
  unsigned int v10; // w8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned int v13; // w11
  unsigned __int64 v14; // x8
  char v15; // w9
  char epcs_capability; // w0
  unsigned __int64 v17; // x9
  void *result; // x0
  unsigned __int8 v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[2703];
  v19[0] = 3;
  wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(v4, v19);
  qdf_mem_copy(a1 + 2758, a2 + 556, 0x5Cu);
  qdf_mem_copy((char *)a1 + 22156, a2 + 648, 0x5Cu);
  v5 = v19[0];
  v6 = a2 + 649;
  v7 = a2[560] & 7;
  v8 = v19[0] & 7;
  v9 = a1[2703];
  if ( v7 >= v19[0] )
    v7 = v19[0] & 7;
  *(_QWORD *)((char *)a1 + 22065) = *(_QWORD *)((char *)a1 + 22065) & 0xFFFFFFFFF8FFFFFFLL | (v7 << 24);
  v10 = a2[652] & 7;
  if ( v10 >= v5 )
    v10 = v8;
  v11 = *(_QWORD *)((char *)a1 + 22157) & 0xFFFFFFFFF8FFFFFFLL | (v10 << 24);
  *(_QWORD *)((char *)a1 + 22157) = v11;
  v12 = v11 & 0xFFFFFFFFC7FFFFFFLL;
  v13 = (*v6 >> 27) & 7;
  if ( v13 >= v5 )
    v13 = v8;
  v14 = v12 | (v13 << 27);
  *(_QWORD *)((char *)a1 + 22157) = v14;
  if ( ((unsigned int)(*(_QWORD *)v6 >> 30) & 7) >= v5 )
    v15 = v8;
  else
    v15 = (*(_QWORD *)v6 >> 30) & 7;
  *(_QWORD *)((char *)a1 + 22157) = v14 & 0xFFFFFFFE3FFFFFFFLL | ((unsigned __int64)(v15 & 7) << 30);
  epcs_capability = wlan_mlme_get_epcs_capability(v9);
  v17 = *(_QWORD *)((char *)a1 + 22157) & 0xFFFFFFFFFFFFFFFELL | epcs_capability & 1;
  *(_QWORD *)((char *)a1 + 22065) = *(_QWORD *)((char *)a1 + 22065) & 0xFFFFFFFFFFFFFFFELL | epcs_capability & 1;
  *(_QWORD *)((char *)a1 + 22157) = v17;
  qdf_mem_copy(a1 + 2781, a1 + 2758, 0x5Cu);
  result = qdf_mem_copy((char *)a1 + 22340, (char *)a1 + 22156, 0x5Cu);
  _ReadStatusReg(SP_EL0);
  return result;
}
