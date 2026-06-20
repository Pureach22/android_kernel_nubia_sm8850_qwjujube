__int64 __fastcall cm_diag_get_auth_enc_type_vdev_id(__int64 a1, _BYTE *a2, _BYTE *a3, _BYTE *a4, unsigned int a5)
{
  unsigned __int8 v7; // w23
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  int *crypto_params; // x0
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w9
  bool v30; // zf

  v7 = a5;
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a5, 77);
  if ( !v9 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL for vdev %d",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "cm_diag_get_auth_enc_type_vdev_id",
             v7);
  v18 = v9;
  crypto_params = (int *)wlan_crypto_vdev_get_crypto_params(v9);
  if ( crypto_params )
  {
    if ( !a2 )
    {
LABEL_23:
      if ( a3 )
      {
        v20 = (unsigned int)crypto_params[1];
        if ( (_DWORD)v20 )
        {
          if ( (v20 & 0x400) != 0 )
          {
            v20 = 6;
          }
          else if ( (v20 & 0x200) != 0 )
          {
            v20 = 5;
          }
          else if ( (v20 & 0x19CC) != 0 )
          {
            v20 = 4;
          }
          else if ( (v20 & 2) != 0 )
          {
            v20 = 3;
          }
          else if ( (v20 & 0x2010) != 0 )
          {
            v20 = 7;
          }
          else if ( (v20 & 0x8001) != 0 )
          {
            v20 = 1;
          }
          else
          {
            v20 = ((unsigned int)v20 >> 15) & 2;
          }
        }
        *a3 = v20;
      }
      if ( a4 )
      {
        v20 = (unsigned int)crypto_params[1];
        if ( (_DWORD)v20 )
        {
          if ( (v20 & 0x400) != 0 )
          {
            v20 = 6;
          }
          else if ( (v20 & 0x200) != 0 )
          {
            v20 = 5;
          }
          else if ( (v20 & 0x19CC) != 0 )
          {
            v20 = 4;
          }
          else if ( (v20 & 2) != 0 )
          {
            v20 = 3;
          }
          else if ( (v20 & 0x2010) != 0 )
          {
            v20 = 7;
          }
          else if ( (v20 & 0x8001) != 0 )
          {
            v20 = 1;
          }
          else
          {
            v20 = ((unsigned int)v20 >> 15) & 2;
          }
        }
        *a4 = v20;
      }
      return wlan_objmgr_vdev_release_ref(v18, 0x4Du, (unsigned int *)v20, v21, v22, v23, v24, v25, v26, v27, v28);
    }
    v29 = *crypto_params;
    v20 = 0;
    if ( *crypto_params && (v29 & 3) == 0 )
    {
      if ( (v29 & 0x10) != 0 )
      {
        v20 = (crypto_params[1] & 0x18001) != 0;
      }
      else
      {
        if ( (v29 & 4) == 0 )
        {
          if ( (v29 & 0x6C8) != 0 )
          {
            v30 = (crypto_params[5] & 0x10300A1) == 0;
            LODWORD(v20) = 4;
            goto LABEL_19;
          }
          if ( (v29 & 0x20) != 0 )
          {
            v30 = (crypto_params[5] & 1) == 0;
            LODWORD(v20) = 2;
          }
          else
          {
            if ( (v29 & 0x100) == 0 )
            {
              v20 = 0;
              goto LABEL_22;
            }
            v30 = (crypto_params[5] & 0x2000) == 0;
            LODWORD(v20) = 6;
          }
LABEL_19:
          if ( v30 )
            v20 = (unsigned int)(v20 + 1);
          else
            v20 = (unsigned int)v20;
          goto LABEL_22;
        }
        v20 = 1;
      }
    }
LABEL_22:
    *a2 = v20;
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: crypto params is null",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "cm_diag_get_auth_enc_type_vdev_id");
  return wlan_objmgr_vdev_release_ref(v18, 0x4Du, (unsigned int *)v20, v21, v22, v23, v24, v25, v26, v27, v28);
}
