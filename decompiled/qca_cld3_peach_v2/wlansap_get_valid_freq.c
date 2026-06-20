__int64 __fastcall wlansap_get_valid_freq(__int64 result, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x8
  __int64 v4; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x21
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x10
  unsigned __int8 v36; // w12
  int *v37; // x14
  __int64 v38; // x15
  int v39; // w13
  int v40; // t1
  unsigned int v41; // [xsp+4h] [xbp-DCh] BYREF
  __int64 v42; // [xsp+8h] [xbp-D8h]
  __int64 v43; // [xsp+10h] [xbp-D0h]
  __int64 v44; // [xsp+18h] [xbp-C8h]
  __int64 v45; // [xsp+20h] [xbp-C0h]
  __int64 v46; // [xsp+28h] [xbp-B8h]
  __int64 v47; // [xsp+30h] [xbp-B0h]
  __int64 v48; // [xsp+38h] [xbp-A8h]
  __int64 v49; // [xsp+40h] [xbp-A0h]
  __int64 v50; // [xsp+48h] [xbp-98h]
  __int64 v51; // [xsp+50h] [xbp-90h]
  __int64 v52; // [xsp+58h] [xbp-88h]
  __int64 v53; // [xsp+60h] [xbp-80h]
  __int64 v54; // [xsp+68h] [xbp-78h]
  _QWORD v55[14]; // [xsp+70h] [xbp-70h] BYREF

  v55[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 1544);
  v54 = 0;
  memset(v55, 0, 104);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v41 = 0;
  if ( v3 )
  {
    if ( *(_BYTE *)(v3 + 40) )
    {
      if ( *(_BYTE *)(v3 + 41) == 1 )
      {
        *(_BYTE *)(v3 + 41) = 0;
        v4 = result;
        result = _qdf_mem_malloc(0x198u, "wlansap_get_valid_freq", 4386);
        if ( result )
        {
          v15 = result;
          context = _cds_get_context(53, (__int64)"sap_get_mac_context", v7, v8, v9, v10, v11, v12, v13, v14);
          if ( context )
          {
            v25 = context;
            if ( !(unsigned int)policy_mgr_reset_sap_mandatory_channels(v4) )
            {
              if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, __int64, unsigned int *, char *, __int64, _QWORD))policy_mgr_get_pcl_for_vdev_id)(
                                   v25[2703],
                                   1,
                                   v15,
                                   &v41,
                                   (char *)v55 + 2,
                                   102,
                                   *(unsigned __int8 *)(a2 + 12)) )
              {
                qdf_trace_msg(
                  0x39u,
                  2u,
                  "%s: Get PCL failed for session %d",
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  "wlansap_get_valid_freq",
                  *(unsigned __int8 *)(a2 + 12));
              }
              else if ( v41 )
              {
                v35 = *(_QWORD *)(a2 + 1544);
                v36 = 0;
                while ( !*(_BYTE *)(v35 + 40) )
                {
LABEL_16:
                  if ( v41 <= ++v36 )
                    goto LABEL_10;
                }
                v37 = *(int **)(v35 + 32);
                v38 = *(unsigned __int8 *)(v35 + 40);
                v39 = *(_DWORD *)(v15 + 4LL * v36);
                while ( 1 )
                {
                  v40 = *v37++;
                  if ( v40 == v39 )
                    break;
                  if ( !--v38 )
                    goto LABEL_16;
                }
                *a3 = v39;
              }
              goto LABEL_10;
            }
            v26 = "%s: failed to reset mandatory channels";
          }
          else
          {
            v26 = "%s: Invalid MAC context";
          }
          qdf_trace_msg(0x39u, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "wlansap_get_valid_freq");
LABEL_10:
          result = _qdf_mem_free(v15);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
