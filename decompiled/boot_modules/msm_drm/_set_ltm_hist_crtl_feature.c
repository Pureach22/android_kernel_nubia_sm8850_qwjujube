__int64 __fastcall set_ltm_hist_crtl_feature(__int64 a1, _QWORD *a2, __int64 a3)
{
  _QWORD *v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x24
  __int64 v8; // x25
  __int64 *v9; // x26
  __int64 result; // x0
  __int64 v13; // x9
  __int64 v14; // x28
  int v15; // w6
  int v16; // w7
  __int64 v17; // x8
  __int64 v18; // x0
  void (*v19)(void); // x8
  __int64 v20; // x0
  int v21; // w7
  __int64 v22; // x0
  __int64 v23; // x10
  __int64 v24; // x2
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 v27; // x2
  __int64 v28; // x10
  __int64 v29; // x8
  __int64 v30; // x2
  __int64 v31; // x10
  __int64 v32; // x8
  __int64 v33; // x2
  __int64 v34; // x10
  __int64 v35; // x8
  void (*v36)(void); // x8
  __int64 v37; // x0
  int v38; // w6
  int v39; // w7
  _QWORD *v40; // x10
  _QWORD *v41; // x8
  __int64 v42; // x11
  _QWORD *v43; // x1
  char v44; // [xsp+0h] [xbp-20h]
  __int64 v45; // [xsp+8h] [xbp-18h] BYREF
  char v46[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  result = 4294967274LL;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a3 )
  {
    v13 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v13 >= 3 )
      goto LABEL_70;
    v7 = a1 + 664;
    if ( *(_QWORD *)(a1 + 664 + 8 * v13) )
    {
      v6 = 7704;
      v3 = a2;
      v8 = a1;
      mutex_lock(a3 + 7704);
      if ( !*v3 || !*(_QWORD *)*v3 )
      {
        v5 = 7752;
        v45 = 0;
        v46[0] = 1;
        v20 = raw_spin_lock_irqsave(a3 + 7752);
        v9 = &qword_294000;
        *(_WORD *)(a3 + 7672) = 256;
        v3 = (_QWORD *)(a3 + 112);
        v4 = v20;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_cp_crtc_disable_ltm_hist",
          4572,
          -1,
          *(_DWORD *)(a3 + 112),
          1,
          -1059143953,
          v21,
          v44);
        v22 = v8;
        v13 = a3 + 7640;
        *(_QWORD *)(a3 + 7640) = a3 + 7640;
        *(_QWORD *)(a3 + 7648) = a3 + 7640;
        *(_QWORD *)(a3 + 7656) = a3 + 7656;
        *(_QWORD *)(a3 + 7664) = a3 + 7656;
        if ( *(_DWORD *)(a3 + 7592) )
        {
          v23 = *(_QWORD *)(a3 + 7600);
          a1 = v23 + 48;
          if ( v23 + 48 != v13 )
          {
            *(_QWORD *)(a3 + 7648) = a1;
            *(_QWORD *)(v23 + 48) = v13;
            *(_QWORD *)(v23 + 56) = v13;
            *(_QWORD *)(a3 + 7640) = a1;
            goto LABEL_24;
          }
          goto LABEL_71;
        }
        goto LABEL_45;
      }
      v9 = (_QWORD *)&unk_1E48;
      v14 = v3[4];
      v4 = raw_spin_lock_irqsave(a3 + 7752);
      if ( !*(_DWORD *)(a3 + 7592) )
      {
        raw_spin_unlock_irqrestore(a3 + 7752, v4);
        _drm_err("LTM buffers are not allocated\n");
        goto LABEL_51;
      }
      if ( (*(_BYTE *)(v14 + 384) & 1) == 0 && *(_BYTE *)(a3 + 7672) == 1 )
      {
LABEL_20:
        raw_spin_unlock_irqrestore(a3 + 7752, v4);
LABEL_51:
        mutex_unlock(a3 + v6);
        result = 0;
        goto LABEL_55;
      }
      v17 = *(_QWORD *)(a3 + 7656);
      v13 = a3 + 7656;
      if ( v17 == a3 + 7656 )
      {
        v40 = *(_QWORD **)(a3 + 7640);
        v41 = (_QWORD *)v40[1];
        v5 = *(v40 - 2) + *((unsigned int *)v40 - 5);
        if ( (_QWORD *)*v41 == v40 && (v42 = *v40, *(_QWORD **)(*v40 + 8LL) == v40) )
        {
          *(_QWORD *)(v42 + 8) = v41;
          *v41 = v42;
        }
        else
        {
          _list_del_entry_valid_or_report(*(_QWORD *)(a3 + 7640));
        }
        *v40 = v40;
        v40[1] = v40;
        v43 = *(_QWORD **)(a3 + 7664);
        if ( v40 != (_QWORD *)v13 && v40 != v43 && *v43 == v13 )
        {
          v18 = v8;
          *(_QWORD *)(a3 + 7664) = v40;
          *v40 = v13;
          v40[1] = v43;
          *v43 = v40;
          if ( (*(_BYTE *)(v14 + 384) & 1) != 0 )
          {
LABEL_14:
            a1 = *(unsigned int *)(v18 + 28);
            if ( (unsigned int)a1 < 3 )
            {
              v19 = *(void (**)(void))(v7 + 8 * a1);
              if ( v19 )
              {
                if ( *((_DWORD *)v19 - 1) != 518117476 )
                  __break(0x8228u);
                v19();
              }
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "_sde_cp_crtc_enable_ltm_hist",
                4555,
                -1,
                4369,
                -1059143953,
                v15,
                v16,
                v44);
              goto LABEL_20;
            }
            do
            {
              do
              {
LABEL_70:
                __break(0x5512u);
LABEL_71:
                _list_add_valid_or_report(a1, v13);
                v22 = v8;
LABEL_24:
                if ( *(_DWORD *)(a3 + 7592) < 2u )
                  break;
                v24 = *(_QWORD *)(a3 + 7640);
                v25 = *(_QWORD *)(a3 + 7608);
                v26 = v25 + 48;
                if ( *(_QWORD *)(v24 + 8) != v13 || v26 == v13 || v24 == v26 )
                {
                  _list_add_valid_or_report(v25 + 48, v13);
                  v22 = v8;
                }
                else
                {
                  *(_QWORD *)(v24 + 8) = v26;
                  *(_QWORD *)(v25 + 48) = v24;
                  *(_QWORD *)(v25 + 56) = v13;
                  *(_QWORD *)v13 = v26;
                }
                if ( *(_DWORD *)(a3 + 7592) < 3u )
                  break;
                v27 = *(_QWORD *)(a3 + 7640);
                v28 = *(_QWORD *)(a3 + 7616);
                v29 = v28 + 48;
                if ( *(_QWORD *)(v27 + 8) != v13 || v29 == v13 || v27 == v29 )
                {
                  _list_add_valid_or_report(v28 + 48, v13);
                  v22 = v8;
                }
                else
                {
                  *(_QWORD *)(v27 + 8) = v29;
                  *(_QWORD *)(v28 + 48) = v27;
                  *(_QWORD *)(v28 + 56) = v13;
                  *(_QWORD *)v13 = v29;
                }
                if ( *(_DWORD *)(a3 + 7592) < 4u )
                  break;
                v30 = *(_QWORD *)(a3 + 7640);
                v31 = *(_QWORD *)(a3 + 7624);
                v32 = v31 + 48;
                if ( *(_QWORD *)(v30 + 8) != v13 || v32 == v13 || v30 == v32 )
                {
                  _list_add_valid_or_report(v31 + 48, v13);
                  v22 = v8;
                }
                else
                {
                  *(_QWORD *)(v30 + 8) = v32;
                  *(_QWORD *)(v31 + 48) = v30;
                  *(_QWORD *)(v31 + 56) = v13;
                  *(_QWORD *)v13 = v32;
                }
                if ( *(_DWORD *)(a3 + 7592) < 5u )
                  break;
                v33 = *(_QWORD *)(a3 + 7640);
                v34 = *(_QWORD *)(a3 + 7632);
                v35 = v34 + 48;
                if ( *(_QWORD *)(v33 + 8) != v13 || v35 == v13 || v33 == v35 )
                {
                  _list_add_valid_or_report(v34 + 48, v13);
                  v22 = v8;
                }
                else
                {
                  *(_QWORD *)(v33 + 8) = v35;
                  *(_QWORD *)(v34 + 48) = v33;
                  *(_QWORD *)(v34 + 56) = v13;
                  *(_QWORD *)v13 = v35;
                }
                a1 = *(unsigned int *)(a3 + 7592);
              }
              while ( (unsigned int)a1 > 5 );
LABEL_45:
              a1 = *(unsigned int *)(v22 + 28);
            }
            while ( (unsigned int)a1 > 2 );
            v36 = *(void (**)(void))(v7 + 8 * a1);
            if ( v36 )
            {
              if ( *((_DWORD *)v36 - 1) != 518117476 )
                __break(0x8228u);
              v36();
            }
            raw_spin_unlock_irqrestore(a3 + v5, v4);
            v37 = v9[191];
            v45 = 0x18000000ALL;
            sde_evtlog_log(v37, "_sde_cp_crtc_disable_ltm_hist", 4584, -1, 4369, -1059143953, v38, v39, v44);
            msm_mode_object_event_notify(v3, *(_QWORD *)a3, &v45, v46);
            goto LABEL_51;
          }
LABEL_13:
          *(_BYTE *)(a3 + 7672) = 1;
          goto LABEL_14;
        }
        _list_add_valid_or_report(v40, v43);
      }
      else
      {
        v5 = *(_QWORD *)(v17 - 16) + *(unsigned int *)(v17 - 20);
        _drm_dev_dbg(0, 0, 1, "ltm_buf_busy list already has a buffer\n");
      }
      v18 = v8;
      if ( (*(_BYTE *)(v14 + 384) & 1) != 0 )
        goto LABEL_14;
      goto LABEL_13;
    }
    if ( (_DWORD)v13 == 1 )
      result = 0;
    else
      result = 4294967274LL;
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
