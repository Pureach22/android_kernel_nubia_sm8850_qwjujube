__int64 __fastcall mhi_reset_chan(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int v5; // w22
  __int64 v6; // x24
  _QWORD *v7; // x23
  __int64 v8; // x8
  __int64 v9; // x25
  __int64 v10; // x0
  unsigned __int64 v11; // x11
  __int64 v12; // x8
  __int64 v13; // x22
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x10
  unsigned __int64 v20; // x13
  __int64 v21; // x14
  unsigned __int64 v22; // x13
  __int64 v24; // x21
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v29; // x21
  void (__fastcall *v30)(__int64, __int64); // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  __int64 v33; // x8
  _DWORD *v34; // x9
  unsigned int v39; // w8
  _QWORD v40[2]; // [xsp+0h] [xbp-20h] BYREF
  int v41; // [xsp+10h] [xbp-10h]
  int v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 394) & 1) == 0 )
  {
    v2 = result;
    v3 = *(int *)(a2 + 200);
    raw_read_lock_bh(result + 320);
    v5 = *(_DWORD *)(a2 + 204);
    v6 = *(_QWORD *)(v2 + 16);
    v7 = (_QWORD *)(*(_QWORD *)(v2 + 248) + 264LL * v5);
    v8 = *(_QWORD *)(v6 + 192);
    v9 = **(_QWORD **)(v2 + 264);
    if ( v8 && !*(_DWORD *)(v8 + 24) )
      ipc_log_string(
        *(_QWORD *)(v8 + 32),
        "[D][%s] Marking all events for chan: %d as stale\n",
        "mhi_mark_stale_events",
        v3);
    v10 = raw_spin_lock_irqsave(v7 + 30);
    v11 = v7[6];
    v12 = v9 + 44LL * v5;
    v13 = v10;
    v14 = *(_QWORD *)(v12 + 28);
    v15 = v14 - v11;
    if ( v14 < v11 || (v14 & 0xF) != 0 || (v16 = v7[13], v16 + v11 <= v14) )
    {
      v24 = *(_QWORD *)(*(_QWORD *)(v2 + 16) + 192LL);
      dev_err(v6 + 40, "[E][%s] Event ring rp points outside of the event ring\n", "mhi_mark_stale_events");
      if ( v24 && *(_DWORD *)(v24 + 24) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v24 + 32),
          "[E][%s] Event ring rp points outside of the event ring\n",
          "mhi_mark_stale_events");
    }
    else
    {
      v17 = v7[9];
      v18 = v7[10];
      v19 = v17 + v15;
      while ( v19 != v18 )
      {
        v20 = *(unsigned int *)(v18 + 12);
        v21 = v20 & 0xFF0000;
        v22 = v20 >> 24;
        if ( v21 == 2228224 && v22 == v3 )
        {
          *(_DWORD *)(v18 + 12) = ((_DWORD)v3 << 24) | 0x510000;
          v17 = v7[9];
          v16 = v7[13];
        }
        v18 += 16;
        if ( v18 == v17 + v16 )
          v18 = v17;
      }
    }
    v25 = *(_QWORD *)(*(_QWORD *)(v2 + 16) + 192LL);
    if ( v25 && !*(_DWORD *)(v25 + 24) )
      ipc_log_string(
        *(_QWORD *)(v25 + 32),
        "[D][%s] Finished marking events as stale events\n",
        "mhi_mark_stale_events");
    raw_spin_unlock_irqrestore(v7 + 30, v13);
    v26 = *(_QWORD *)(a2 + 144);
    v27 = *(_QWORD *)(a2 + 152);
    v40[1] = 0;
    v41 = 0;
    v40[0] = 0;
    v42 = -107;
    if ( v26 != v27 )
    {
      _X22 = (unsigned int *)(v2 + 356);
      do
      {
        v29 = *(_QWORD *)(a2 + 48);
        if ( *(_DWORD *)(a2 + 216) == 1 )
        {
          __asm { PRFM            #0x11, [X22] }
          do
            v39 = __ldxr(_X22);
          while ( __stxr(v39 - 1, _X22) );
          if ( (*(_BYTE *)(v29 + 53) & 1) == 0 )
          {
LABEL_32:
            v30 = *(void (__fastcall **)(__int64, __int64))(v2 + 560);
            if ( *((_DWORD *)v30 - 1) != -1374741734 )
              __break(0x8228u);
            v30(v2, v29);
          }
        }
        else if ( (*(_BYTE *)(v29 + 53) & 1) == 0 )
        {
          goto LABEL_32;
        }
        v31 = *(_QWORD *)(a2 + 48) + *(_QWORD *)(a2 + 64);
        if ( v31 >= *(_QWORD *)(a2 + 40) + *(_QWORD *)(a2 + 72) )
          v31 = *(_QWORD *)(a2 + 40);
        *(_QWORD *)(a2 + 48) = v31;
        __dmb(0xAu);
        v32 = *(_QWORD *)(a2 + 144) + *(_QWORD *)(a2 + 160);
        if ( v32 >= *(_QWORD *)(a2 + 136) + *(_QWORD *)(a2 + 168) )
          v32 = *(_QWORD *)(a2 + 136);
        *(_QWORD *)(a2 + 144) = v32;
        __dmb(0xAu);
        if ( *(_BYTE *)(a2 + 395) == 1 )
        {
          kfree(*(_QWORD *)(v29 + 24));
        }
        else
        {
          v33 = *(_QWORD *)(a2 + 272);
          v34 = *(_DWORD **)(a2 + 280);
          v40[0] = *(_QWORD *)(v29 + 24);
          if ( *(v34 - 1) != -2026744486 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD *))v34)(v33, v40);
        }
      }
      while ( *(_QWORD *)(a2 + 144) != *(_QWORD *)(a2 + 152) );
    }
    result = raw_read_unlock_bh(v2 + 320);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
