__int64 __fastcall ce_per_engine_servicereap(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x8
  unsigned __int64 v7; // x8
  __int64 v8; // x22
  _DWORD *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned __int64 StatusReg; // x24
  _DWORD *v13; // x8
  __int64 v14; // x25
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  void (__fastcall *v23)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v24; // x3
  __int64 v25; // [xsp+0h] [xbp-40h]
  int v26; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h] BYREF
  __int64 v28; // [xsp+18h] [xbp-28h] BYREF
  __int64 v29; // [xsp+20h] [xbp-20h] BYREF
  __int64 v30; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v31[2]; // [xsp+30h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31[0] = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  v26 = 0;
  if ( a2 >= 0xC )
    __break(0x5512u);
  v4 = *(_QWORD *)(a1 + 8LL * a2 + 480);
  result = hif_target_sleep_state_adjust(a1, 0, 1);
  if ( (result & 0x80000000) == 0 )
  {
    hif_record_ce_desc_event(a1, a2, 21, 0, 0, 0, v6);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v4 + 168);
      if ( *(_QWORD *)(v4 + 72) )
      {
LABEL_7:
        v8 = *(_QWORD *)(a1 + 30696);
        v9 = *(_DWORD **)(v8 + 80);
        if ( *(v9 - 1) != -988321398 )
          __break(0x8228u);
        if ( !((unsigned int (__fastcall *)(__int64, _QWORD *, __int64 *, __int64 *, char *, __int64 *, char *, __int64 *, int *))v9)(
                v4,
                v31,
                &v30,
                &v29,
                (char *)&v28 + 4,
                &v28,
                (char *)&v27 + 4,
                &v27,
                &v26) )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          do
          {
            if ( a2 == 4 )
            {
              v14 = v31[0];
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v31[0] + 56LL);
                v15 = *(_QWORD *)(v14 + 64);
              }
              else
              {
                raw_spin_lock_bh(v14 + 56);
                v15 = *(_QWORD *)(v14 + 64) | 1LL;
                *(_QWORD *)(v14 + 64) = v15;
              }
              ++*(_DWORD *)(v14 + 72);
              if ( (v15 & 1) != 0 )
              {
                *(_QWORD *)(v14 + 64) = v15 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v14 + 56);
              }
              else
              {
                raw_spin_unlock(v14 + 56);
              }
            }
            else
            {
              v16 = *(_QWORD *)(v4 + 176);
              if ( (v16 & 1) != 0 )
              {
                *(_QWORD *)(v4 + 176) = v16 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v4 + 168);
              }
              else
              {
                raw_spin_unlock(v4 + 168);
              }
              v18 = v30;
              v17 = v31[0];
              v20 = (unsigned int)v28;
              v19 = HIDWORD(v28);
              v22 = (unsigned int)v27;
              v21 = HIDWORD(v27);
              v23 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v4 + 72);
              v24 = v29;
              LODWORD(v25) = v26;
              if ( *((_DWORD *)v23 - 1) != -860884680 )
                __break(0x8228u);
              v23(v4, v17, v18, v24, v19, v20, v21, v22, v25);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v4 + 168);
              }
              else
              {
                raw_spin_lock_bh(v4 + 168);
                *(_QWORD *)(v4 + 176) |= 1uLL;
              }
            }
            v13 = *(_DWORD **)(v8 + 80);
            if ( *(v13 - 1) != -988321398 )
              __break(0x8228u);
          }
          while ( !((unsigned int (__fastcall *)(__int64, _QWORD *, __int64 *, __int64 *, char *, __int64 *, char *, __int64 *, int *))v13)(
                     v4,
                     v31,
                     &v30,
                     &v29,
                     (char *)&v28 + 4,
                     &v28,
                     (char *)&v27 + 4,
                     &v27,
                     &v26) );
        }
      }
    }
    else
    {
      raw_spin_lock_bh(v4 + 168);
      *(_QWORD *)(v4 + 176) |= 1uLL;
      if ( *(_QWORD *)(v4 + 72) )
        goto LABEL_7;
    }
    v10 = *(_QWORD *)(v4 + 176);
    if ( (v10 & 1) != 0 )
    {
      *(_QWORD *)(v4 + 176) = v10 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v4 + 168);
    }
    else
    {
      raw_spin_unlock(v4 + 168);
    }
    hif_record_ce_desc_event(a1, a2, 22, 0, 0, 0, v11);
    result = hif_target_sleep_state_adjust(a1, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
