__int64 __fastcall ll_lt_sap_invoke_bs_requester_cbks(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x19
  __int64 v14; // x26
  __int64 v15; // x2
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x1
  __int64 v19; // x8
  __int64 v20; // x27
  _DWORD *v21; // x8
  unsigned int v22; // w25
  __int64 v23; // x9
  _DWORD **comp_private_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _DWORD *v33; // x8
  const char *v34; // x2
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x11
  __int64 v38; // x10
  __int64 v39; // x12
  int v40; // w11
  int v41; // w13

  v10 = *(_QWORD *)(*(_QWORD *)result + 152LL);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 80);
    if ( v11 )
    {
      v12 = result;
      v14 = 0;
      while ( 1 )
      {
        v20 = v12 + v14;
        v21 = *(_DWORD **)(v12 + v14 + 272);
        if ( !v21 )
          goto LABEL_8;
        v22 = *(_DWORD *)(v20 + 264);
        if ( v22 == 1 )
          goto LABEL_8;
        v23 = v12 + v14;
        if ( a2 != 15 || *(_DWORD *)(v23 + 268) != 2 )
        {
          v15 = *(unsigned int *)(v23 + 260);
          v16 = *(unsigned int *)(v23 + 280);
          v17 = *(_QWORD *)(v23 + 288);
          v18 = *(unsigned __int8 *)(v20 + 256);
          if ( *(v21 - 1) != -1172045929 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, __int64))v21)(
                     v11,
                     v18,
                     v15,
                     a2,
                     v16,
                     v17);
          goto LABEL_7;
        }
        comp_private_obj = (_DWORD **)wlan_objmgr_psoc_get_comp_private_obj(v11, 0x34u);
        if ( comp_private_obj )
        {
          v33 = *comp_private_obj;
          if ( *comp_private_obj )
          {
            if ( *(v33 - 1) != 1380159806 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v33)(v11, v22, 2);
            goto LABEL_7;
          }
          v34 = "%s: deliver_audio_transport_switch_resp op is NULL";
        }
        else
        {
          v34 = "%s: psoc_ll_sap_obj is null";
        }
        result = qdf_trace_msg(
                   0xA1u,
                   2u,
                   v34,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   "ll_lt_sap_deliver_audio_transport_switch_resp_to_fw");
LABEL_7:
        v19 = v12 + v14;
        *(_QWORD *)(v20 + 272) = 0;
        *(_QWORD *)(v19 + 288) = 0;
        *(_DWORD *)(v19 + 280) = 0;
LABEL_8:
        v14 += 40;
        if ( v14 == 200 )
        {
          v35 = 0;
          while ( 1 )
          {
            if ( !v35 )
              goto LABEL_24;
            v36 = v12 + v35;
            v37 = *(_QWORD *)(v12 + v35 + 272);
            if ( !v37 )
              goto LABEL_24;
            v38 = v12 + v35;
            if ( *(_QWORD *)(v12 + 272) )
            {
              if ( v35 == 40 )
                goto LABEL_24;
            }
            else
            {
              v39 = *(_QWORD *)(v38 + 288);
              *(_QWORD *)(v12 + 272) = v37;
              *(_QWORD *)(v12 + 288) = v39;
              LODWORD(v39) = *(_DWORD *)(v38 + 280);
              *(_QWORD *)(v38 + 288) = 0;
              *(_DWORD *)(v12 + 280) = v39;
              v40 = *(_DWORD *)(v38 + 264);
              LODWORD(v39) = *(_DWORD *)(v38 + 268);
              *(_QWORD *)(v36 + 272) = 0;
              *(_DWORD *)(v38 + 280) = 0;
              *(_DWORD *)(v12 + 264) = v40;
              LOBYTE(v40) = *(_BYTE *)(v36 + 256);
              v41 = *(_DWORD *)(v38 + 260);
              *(_DWORD *)(v12 + 268) = v39;
              *(_BYTE *)(v12 + 256) = v40;
              v37 = 0;
              *(_DWORD *)(v12 + 260) = v41;
              if ( v35 == 40 )
                goto LABEL_24;
            }
            if ( *(_QWORD *)(v12 + 312) )
            {
              if ( v35 == 80 )
                goto LABEL_24;
            }
            else
            {
              *(_QWORD *)(v12 + 312) = v37;
              v37 = 0;
              *(_QWORD *)(v12 + 328) = *(_QWORD *)(v38 + 288);
              *(_DWORD *)(v12 + 320) = *(_DWORD *)(v38 + 280);
              *(_DWORD *)(v12 + 304) = *(_DWORD *)(v38 + 264);
              *(_BYTE *)(v12 + 296) = *(_BYTE *)(v36 + 256);
              *(_DWORD *)(v12 + 300) = *(_DWORD *)(v38 + 260);
              *(_DWORD *)(v12 + 308) = *(_DWORD *)(v38 + 268);
              *(_QWORD *)(v36 + 272) = 0;
              *(_QWORD *)(v38 + 288) = 0;
              *(_DWORD *)(v38 + 280) = 0;
              if ( v35 == 80 )
                goto LABEL_24;
            }
            if ( *(_QWORD *)(v12 + 352) )
            {
              if ( v35 != 120 )
                goto LABEL_39;
            }
            else
            {
              *(_QWORD *)(v12 + 352) = v37;
              v37 = 0;
              *(_QWORD *)(v12 + 368) = *(_QWORD *)(v38 + 288);
              *(_DWORD *)(v12 + 360) = *(_DWORD *)(v38 + 280);
              *(_DWORD *)(v12 + 344) = *(_DWORD *)(v38 + 264);
              *(_BYTE *)(v12 + 336) = *(_BYTE *)(v36 + 256);
              *(_DWORD *)(v12 + 340) = *(_DWORD *)(v38 + 260);
              *(_DWORD *)(v12 + 348) = *(_DWORD *)(v38 + 268);
              *(_QWORD *)(v36 + 272) = 0;
              *(_QWORD *)(v38 + 288) = 0;
              *(_DWORD *)(v38 + 280) = 0;
              if ( v35 != 120 )
              {
LABEL_39:
                if ( !*(_QWORD *)(v12 + 392) )
                {
                  *(_QWORD *)(v12 + 392) = v37;
                  *(_QWORD *)(v12 + 408) = *(_QWORD *)(v38 + 288);
                  *(_DWORD *)(v12 + 400) = *(_DWORD *)(v38 + 280);
                  *(_DWORD *)(v12 + 384) = *(_DWORD *)(v38 + 264);
                  *(_BYTE *)(v12 + 376) = *(_BYTE *)(v36 + 256);
                  *(_DWORD *)(v12 + 380) = *(_DWORD *)(v38 + 260);
                  *(_DWORD *)(v12 + 388) = *(_DWORD *)(v38 + 268);
                  *(_QWORD *)(v36 + 272) = 0;
                  *(_QWORD *)(v38 + 288) = 0;
                  *(_DWORD *)(v38 + 280) = 0;
                }
              }
            }
LABEL_24:
            v35 += 40;
            if ( v35 == 200 )
              return result;
          }
        }
      }
    }
  }
  return qdf_trace_msg(
           0xA1u,
           2u,
           "%s: BS_SM invalid psoc",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "ll_lt_sap_invoke_bs_requester_cbks");
}
