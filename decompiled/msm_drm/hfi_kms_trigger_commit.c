__int64 __fastcall hfi_kms_trigger_commit(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 result; // x0
  int v11; // w7
  __int64 v12; // x28
  char *v13; // x27
  _QWORD **v14; // x20
  unsigned int v15; // w23
  __int64 *v16; // x8
  __int64 v17; // x23
  __int64 v18; // x1
  int display_id; // w0
  __int64 v20; // x8
  unsigned __int16 v21; // w24
  _QWORD *v22; // x8
  __int64 v23; // x25
  char *v24; // x22
  _QWORD *v25; // x24
  __int64 v26; // x27
  int v27; // w0
  int v28; // w6
  int v29; // w7
  char v30; // [xsp+0h] [xbp-20h]
  char v31; // [xsp+0h] [xbp-20h]
  __int64 v32; // [xsp+8h] [xbp-18h]
  int v33; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+18h] [xbp-8h]

  result = 4294967274LL;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 2;
  if ( a1 && a2 )
  {
    v32 = *(_QWORD *)(a1 + 6440);
    sde_evtlog_log(sde_dbg_base_evtlog, "hfi_kms_trigger_commit", 102, -1, 33554435, 4369, -1059143953, a8, v30);
    if ( *(int *)(*(_QWORD *)(a2 + 8) + 860LL) >= 1 )
    {
      v12 = 0;
      v13 = "ress";
      v14 = (_QWORD **)(v32 + 72);
      do
      {
        v16 = (__int64 *)(*(_QWORD *)(a2 + 32) + 56 * v12);
        v17 = *v16;
        if ( *v16 )
        {
          v18 = v16[3];
          if ( (*(_BYTE *)(*(_QWORD *)(v17 + 2008) + 9LL) & 1) != 0
            || (*(_BYTE *)(v18 + 9) & 1) != 0
            || (*(_BYTE *)(v18 + 10) & 4) != 0 )
          {
            display_id = hfi_crtc_get_display_id((__int64 *)v17, v18);
            v20 = *((_QWORD *)v13 + 500);
            if ( display_id == -1 )
            {
              if ( (v20 & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "no valid display for crtc:%d\n", *(_DWORD *)(v17 + 112));
            }
            else
            {
              v21 = display_id;
              if ( (v20 & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "getting cmd buffer for disp_id:%d\n", display_id);
              if ( !v32 )
              {
                printk(&unk_226F51, "hfi_kms_get_cmd_buf");
LABEL_30:
                printk(&unk_211E26, "hfi_kms_trigger_commit");
                result = 4294967274LL;
                goto LABEL_31;
              }
              v22 = *v14;
              if ( *v14 == v14 )
                goto LABEL_30;
              while ( *((_DWORD *)v22 - 14) != 1 || *((_DWORD *)v22 - 12) != v21 )
              {
                v22 = (_QWORD *)*v22;
                if ( v22 == v14 )
                  goto LABEL_30;
              }
              v23 = (__int64)(v22 - 13);
              if ( v22 == (_QWORD *)&unk_68 )
                goto LABEL_30;
              v24 = v13;
              hfi_adapter_add_set_property((__int64)(v22 - 13), 33554435, 0, 1u, (__int64)&v33, 4u, 0);
              v25 = *(_QWORD **)(*(_QWORD *)v17 + 816LL);
              v26 = *(_QWORD *)v17 + 816LL;
              while ( v25 != (_QWORD *)v26 )
              {
                if ( v25[9] == v17 )
                {
                  v27 = sde_encoder_helper_inc_pending(v25 - 1);
                  sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "hfi_kms_trigger_commit",
                    130,
                    -1,
                    v27,
                    -1059143953,
                    v28,
                    v29,
                    v31);
                }
                v25 = (_QWORD *)*v25;
              }
              v15 = hfi_adapter_set_cmd_buf(v23);
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "hfi_kms_trigger_commit",
                134,
                -1,
                33554435,
                v15,
                13107,
                -1059143953,
                v31);
              v13 = v24;
              if ( v15 )
              {
                printk(&unk_25A6A5, "hfi_kms_trigger_commit");
                result = v15;
                goto LABEL_31;
              }
            }
          }
        }
        ++v12;
      }
      while ( v12 < *(int *)(*(_QWORD *)(a2 + 8) + 860LL) );
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "hfi_kms_trigger_commit", 142, -1, 33554435, 8738, -1059143953, v11, v31);
    result = 0;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
