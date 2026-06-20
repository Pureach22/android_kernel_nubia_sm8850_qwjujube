__int64 __fastcall populate_dot11f_qcn_ie(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v6; // x21
  __int64 v7; // x8
  int v8; // w8
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  int v19; // w22
  size_t v20; // x2
  int v21; // [xsp+0h] [xbp-10h] BYREF
  char v22; // [xsp+4h] [xbp-Ch]
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)a3 = 0;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3336LL) == 1 && (a4 == 255 || a4 == 1) )
    *(_DWORD *)a3 = 65793;
  if ( *(_BYTE *)(a2 + 7170) && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2680LL) == 1 )
  {
    *(_BYTE *)a3 = 1;
    *(_WORD *)(a3 + 4) = 257;
  }
  if ( *(_BYTE *)(a2 + 8676) == 1 && *(_DWORD *)(a2 + 424) != 5 )
  {
    v6 = a2;
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284)) )
    {
      a2 = v6;
      if ( *(_DWORD *)(v6 + 88) == 1
        && *(_DWORD *)(v6 + 7176) == 1
        && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 1476LL) & 2) != 0 )
      {
        goto LABEL_18;
      }
      v7 = 1472;
    }
    else
    {
      v7 = 1474;
      a2 = v6;
    }
    v8 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 8) + v7);
    if ( v8 )
    {
      *(_BYTE *)(a3 + 21) = v8;
      *(_BYTE *)a3 = 1;
      *(_BYTE *)(a3 + 20) = 1;
      *(_BYTE *)(a3 + 22) = BYTE1(v8);
    }
  }
LABEL_18:
  result = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10));
  if ( (result & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Populate edca/pifs param ie for ll sap",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "populate_dot11f_qcn_ie");
    v22 = 0;
    *(_BYTE *)a3 = 1;
    *(_BYTE *)(a3 + 23) = 1;
    v18 = *(_QWORD *)(a1 + 8);
    v21 = 0;
    v19 = *(_DWORD *)(v18 + 1028);
    result = wlan_mlme_set_edca_pifs_param((__int64)&v21, (unsigned __int8)v19);
    *(_BYTE *)(a3 + 24) = v19;
    if ( !(_BYTE)v19 )
    {
      v20 = 4;
      goto LABEL_23;
    }
    if ( (unsigned __int8)v19 == 1 )
    {
      v20 = 3;
LABEL_23:
      *(_BYTE *)(a3 + 25) = v20;
      result = (__int64)qdf_mem_copy((void *)(a3 + 26), (char *)&v21 + 1, v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
