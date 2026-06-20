__int64 __fastcall ml_nlink_handle_dynamic_inactive(__int64 result, __int64 a2, __int64 a3, unsigned __int16 *a4)
{
  int v4; // w9
  __int64 v8; // x21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  int v18; // w27
  __int64 i; // x28
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w9
  int v24; // w10
  int v25; // w11
  __int64 v26; // x4
  __int64 v27; // [xsp+0h] [xbp-D0h]
  __int64 v28; // [xsp+8h] [xbp-C8h]
  __int64 v29; // [xsp+20h] [xbp-B0h]
  unsigned __int8 v30; // [xsp+28h] [xbp-A8h]
  unsigned int v31; // [xsp+30h] [xbp-A0h] BYREF
  _BYTE v32[4]; // [xsp+34h] [xbp-9Ch] BYREF
  int v33; // [xsp+38h] [xbp-98h] BYREF
  char v34; // [xsp+3Ch] [xbp-94h]
  int v35; // [xsp+40h] [xbp-90h] BYREF
  char v36; // [xsp+44h] [xbp-8Ch]
  int v37; // [xsp+48h] [xbp-88h] BYREF
  char v38; // [xsp+4Ch] [xbp-84h]
  _QWORD v39[5]; // [xsp+50h] [xbp-80h] BYREF
  _QWORD v40[2]; // [xsp+78h] [xbp-58h] BYREF
  int v41; // [xsp+88h] [xbp-48h]
  _QWORD v42[2]; // [xsp+90h] [xbp-40h] BYREF
  int v43; // [xsp+A0h] [xbp-30h]
  _QWORD v44[2]; // [xsp+A8h] [xbp-28h] BYREF
  int v45; // [xsp+B8h] [xbp-18h]
  __int64 v46; // [xsp+C0h] [xbp-10h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a3 + 8);
  v32[0] = 0;
  if ( v4 )
  {
    if ( *(_WORD *)(a3 + 10) )
    {
      if ( *(_WORD *)(a3 + 12) )
      {
        if ( v4 == *((unsigned __int8 *)a4 + 8)
          && *(unsigned __int16 *)(a3 + 10) == a4[5]
          && (*(unsigned __int16 *)(a3 + 12) & ~a4[1]) != 0 )
        {
          v8 = result;
          v38 = 0;
          v37 = 0;
          v44[0] = 0;
          v44[1] = 0;
          v45 = 0;
          v42[0] = 0;
          v42[1] = 0;
          v43 = 0;
          v35 = 0;
          v36 = 0;
          v40[0] = 0;
          v40[1] = 0;
          v41 = 0;
          v33 = 0;
          v34 = 0;
          memset(v39, 0, sizeof(v39));
          result = policy_mgr_get_legacy_conn_info(result, (__int64)&v37, (__int64)v44, (__int64)v42, 5u);
          v30 = result;
          if ( (_BYTE)result )
          {
            result = ml_nlink_get_link_info(
                       v8,
                       a2,
                       1u,
                       5u,
                       v39,
                       (unsigned int *)v40,
                       (unsigned __int8 *)&v35,
                       &v33,
                       v32,
                       &v31);
            v29 = v32[0];
            if ( v32[0] >= 2uLL )
            {
              v17 = 0;
              v18 = 0;
              do
              {
                if ( v17 == 5 )
                  goto LABEL_27;
                if ( ((*(unsigned __int16 *)(a3 + 12) >> *((_BYTE *)&v33 + v17)) & 1) != 0 )
                {
                  for ( i = 0; 4LL * v30 != i; i += 4 )
                  {
                    if ( i == 20 )
                      goto LABEL_27;
                    if ( *(_DWORD *)((char *)v42 + i) == 1 )
                    {
                      if ( (v17 & 0x3FFFFFFFFFFFFFFFLL) == 5 )
                      {
                        __break(1u);
LABEL_27:
                        __break(0x5512u);
                      }
                      result = policy_mgr_2_freq_always_on_same_mac(
                                 v8,
                                 *(unsigned int *)((char *)v44 + i),
                                 *((unsigned int *)v40 + v17));
                      if ( (result & 1) != 0
                        || v30 != 1
                        && (result = policy_mgr_are_2_freq_on_same_mac(
                                       v8,
                                       *(_DWORD *)((char *)v44 + i),
                                       *((_DWORD *)v40 + v17)),
                            (result & 1) != 0) )
                      {
                        v18 |= 1 << *((_BYTE *)&v33 + v17);
                        result = qdf_trace_msg(
                                   0x8Fu,
                                   8u,
                                   "%s: force dynamic inactive link id %d freq %d for sap freq %d",
                                   v9,
                                   v10,
                                   v11,
                                   v12,
                                   v13,
                                   v14,
                                   v15,
                                   v16,
                                   "ml_nlink_handle_dynamic_inactive");
                      }
                    }
                  }
                }
                ++v17;
              }
              while ( v17 != v29 );
              if ( v18 )
              {
                v20 = *a4;
                v21 = *((unsigned __int8 *)a4 + 8);
                v22 = a4[5];
                v23 = *((unsigned __int8 *)a4 + 4);
                v24 = a4[3];
                v25 = a4[6];
                v26 = (unsigned __int16)(a4[1] | v18);
                a4[1] |= v18;
                LODWORD(v28) = v24;
                LODWORD(v27) = v23;
                result = qdf_trace_msg(
                           0x8Fu,
                           8u,
                           "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
                           v9,
                           v10,
                           v11,
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           "ml_nlink_handle_dynamic_inactive",
                           v26,
                           v20,
                           v21,
                           v22,
                           v27,
                           v28,
                           v25);
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
