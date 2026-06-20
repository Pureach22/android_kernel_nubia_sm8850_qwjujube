__int64 __fastcall policy_mgr_promote_best_sap_channel_in_pcl(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int64 v15; // x8
  __int64 v16; // x21
  unsigned __int8 v17; // w22
  __int64 v18; // x24
  unsigned int v19; // w9
  unsigned __int8 v20; // w8
  __int64 v21; // x26
  unsigned int v22; // w0
  int v23; // w9
  _BYTE v24[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v24[0] = 0;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 44);
  if ( result )
  {
    v15 = *(unsigned int *)(result + 16);
    v16 = result;
    if ( (_DWORD)v15 == 1 )
    {
      wlan_get_sap_best_channel_2ghz(result, v25, v24);
      v15 = v25[0];
      if ( v25[0] )
      {
        v15 = v24[0];
        if ( v24[0] )
        {
          v15 = *a4;
          if ( (_DWORD)v15 )
          {
            v17 = 0;
            while ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 4LL * v17)) )
            {
              v15 = *a4;
              if ( (unsigned int)v15 <= ++v17 )
                goto LABEL_23;
            }
            if ( (v17 & 0x80) == 0 )
            {
              v15 = v24[0];
              if ( v24[0] )
              {
                v18 = 0;
                while ( 1 )
                {
                  if ( *(_DWORD *)(v25[0] + 4 * v18) )
                  {
                    v19 = *a4;
                    if ( *a4 > v17 )
                      break;
                  }
LABEL_14:
                  if ( ++v18 >= (unsigned __int64)(unsigned int)v15 )
                    goto LABEL_23;
                }
                v20 = v17;
                while ( 1 )
                {
                  v21 = v20;
                  v22 = *(_DWORD *)(v25[0] + 4 * v18);
                  if ( v22 == *(_DWORD *)(a3 + 4LL * v20) )
                  {
                    if ( wlan_reg_is_24ghz_ch_freq(v22) )
                    {
                      v15 = *(unsigned int *)(a3 + 4 * v21);
                      v23 = *(_DWORD *)(a3 + 4LL * v17);
                      *(_DWORD *)(a3 + 4LL * v17) = v15;
                      *(_DWORD *)(a3 + 4 * v21) = v23;
                      break;
                    }
                    v19 = *a4;
                  }
                  v20 = v21 + 1;
                  if ( v19 <= (unsigned __int8)(v21 + 1) )
                  {
                    v15 = v24[0];
                    goto LABEL_14;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_23:
    result = wlan_objmgr_vdev_release_ref(v16, 0x2Cu, (unsigned int *)v15, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
