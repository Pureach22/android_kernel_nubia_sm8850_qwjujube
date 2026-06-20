__int64 __fastcall parse_xfer_event(__int64 a1, __int64 *a2, __int64 a3)
{
  unsigned int v6; // w8
  unsigned int v7; // w20
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x0
  unsigned __int64 v11; // x10
  unsigned __int64 v12; // x11
  unsigned __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x21
  __int64 v17; // x28
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x24
  __int64 lock_irqsave; // x0
  __int64 v22; // x8
  __int64 v23; // x23
  __int64 v24; // x9
  __int64 v25; // x10
  void (__fastcall *v26)(__int64, __int64, __int64); // x8
  __int64 v27; // x2
  __int64 v28; // x26
  int v29; // w21
  __int64 v30; // x8
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x1
  unsigned __int64 v33; // x8
  __int64 v34; // x9
  unsigned __int64 v35; // x8
  __int64 v36; // x0
  void (__fastcall *v37)(__int64, __int64 *); // x8
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x0
  __int64 v41; // x2
  unsigned int v47; // w8
  __int64 v48; // x0
  __int64 result; // x0
  __int64 v50; // x21
  __int64 v51; // [xsp+0h] [xbp-70h]
  __int64 v52; // [xsp+8h] [xbp-68h]
  __int64 v53; // [xsp+10h] [xbp-60h]
  __int64 v54; // [xsp+18h] [xbp-58h] BYREF
  __int64 v55; // [xsp+20h] [xbp-50h]
  __int64 v56; // [xsp+28h] [xbp-48h]
  _QWORD v57[8]; // [xsp+30h] [xbp-40h] BYREF

  v57[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_DWORD *)a2 + 2);
  v55 = 0;
  v56 = 0;
  v54 = 0;
  v7 = HIBYTE(v6);
  if ( HIBYTE(v6) == 3 )
    v8 = -75;
  else
    v8 = 0;
  HIDWORD(v56) = v8;
  v9 = *(_QWORD *)(a1 + 16);
  v10 = a3 + 368;
  v52 = v9;
  if ( v7 < 5 )
  {
    raw_read_lock_bh(v10);
    v53 = 0;
  }
  else
  {
    v53 = raw_write_lock_irqsave(v10);
  }
  if ( *(_DWORD *)(a3 + 260) == 1 )
  {
    if ( v7 - 2 >= 3 )
    {
      if ( v7 - 5 >= 2 )
      {
        _warn_printk("Unknown event 0x%x\n", v7);
        __break(0x800u);
      }
      else
      {
        *(_BYTE *)(a3 + 225) = 1;
        lock_irqsave = raw_read_lock_irqsave(a1 + 320);
        v22 = *(_QWORD *)(a3 + 152);
        v23 = lock_irqsave;
        if ( v22 != *(_QWORD *)(a3 + 144) && (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 )
        {
          v24 = *(_QWORD *)(a3 + 136);
          v25 = *(_QWORD *)(a3 + 112);
          __dmb(2u);
          **(_QWORD **)(a3 + 120) = v22 - v24 + v25;
          v26 = *(void (__fastcall **)(__int64, __int64, __int64))(a3 + 248);
          v27 = *(_QWORD *)(a3 + 192);
          if ( *((_DWORD *)v26 - 1) != -396405511 )
            __break(0x8228u);
          v26(a1, a3 + 224, v27);
        }
        raw_read_unlock_irqrestore(a1 + 320, v23);
      }
    }
    else
    {
      v11 = *a2;
      v12 = *(_QWORD *)(a3 + 112);
      v13 = *a2 - v12;
      if ( *a2 < v12 || (v11 & 0xF) != 0 || (v14 = *(_QWORD *)(a3 + 168), v14 + v12 <= v11) )
      {
        v50 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        dev_err(v52 + 40, "[E][%s] Event element points outside of the tre ring\n", "parse_xfer_event");
        if ( v50 && *(_DWORD *)(v50 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v50 + 32),
            "[E][%s] Event element points outside of the tre ring\n",
            "parse_xfer_event");
      }
      else
      {
        v15 = *(_QWORD *)(a3 + 136);
        v16 = *(_QWORD *)(a3 + 144);
        v17 = v15 + v13;
        v18 = v15 + v13 + 16;
        if ( v18 >= v15 + v14 )
          v19 = *(_QWORD *)(a3 + 136);
        else
          v19 = v18;
        LODWORD(v56) = *(_DWORD *)(a3 + 216);
        if ( v16 != v19 )
        {
          _X25 = (unsigned int *)(a1 + 356);
          do
          {
            v28 = *(_QWORD *)(a3 + 48);
            if ( v16 == v17 )
              LOWORD(v29) = *((_WORD *)a2 + 4);
            else
              v29 = *(_DWORD *)(v28 + 40);
            v30 = *(_QWORD *)(a3 + 48);
            if ( (*(_BYTE *)(v28 + 53) & 1) == 0 )
            {
              v31 = *(void (__fastcall **)(__int64, __int64))(a1 + 560);
              v32 = *(_QWORD *)(a3 + 48);
              if ( *((_DWORD *)v31 - 1) != -1374741734 )
                __break(0x8228u);
              v31(a1, v32);
              v30 = *(_QWORD *)(a3 + 48);
            }
            v33 = v30 + *(_QWORD *)(a3 + 64);
            if ( (unsigned __int16)v29 >= (unsigned int)*(unsigned __int16 *)(v28 + 40) )
              v34 = *(unsigned __int16 *)(v28 + 40);
            else
              v34 = (unsigned __int16)v29;
            if ( v33 >= *(_QWORD *)(a3 + 40) + *(_QWORD *)(a3 + 72) )
              v33 = *(_QWORD *)(a3 + 40);
            v54 = *(_QWORD *)(v28 + 24);
            v55 = v34;
            *(_QWORD *)(a3 + 48) = v33;
            __dmb(0xAu);
            v35 = *(_QWORD *)(a3 + 144) + *(_QWORD *)(a3 + 160);
            if ( v35 >= *(_QWORD *)(a3 + 136) + *(_QWORD *)(a3 + 168) )
              v35 = *(_QWORD *)(a3 + 136);
            *(_QWORD *)(a3 + 144) = v35;
            __dmb(0xAu);
            v16 = *(_QWORD *)(a3 + 144);
            raw_read_unlock_bh(a3 + 368);
            v36 = *(_QWORD *)(a3 + 272);
            v37 = *(void (__fastcall **)(__int64, __int64 *))(a3 + 280);
            if ( *((_DWORD *)v37 - 1) != -2026744486 )
              __break(0x8228u);
            v37(v36, &v54);
            if ( *(_DWORD *)(a3 + 216) == 1 )
            {
              __asm { PRFM            #0x11, [X25] }
              do
                v47 = __ldxr(_X25);
              while ( __stxr(v47 - 1, _X25) );
            }
            if ( *(_BYTE *)(a3 + 395) == 1 )
            {
              v38 = *(_QWORD *)(v28 + 24);
              v39 = *(_QWORD *)(v28 + 40);
              v40 = *(_QWORD *)(a3 + 272);
              v41 = *(unsigned int *)(a3 + 216);
              v57[6] = 0;
              v57[4] = 0;
              v57[1] = 0;
              v57[2] = 0;
              v57[0] = v38;
              v57[3] = v38;
              v57[5] = v39;
              if ( (unsigned int)mhi_queue(v40, v57, v41, 2) )
              {
                v51 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                dev_err(
                  v52 + 40,
                  "[E][%s] Error recycling buffer for chan:%d\n",
                  "parse_xfer_event",
                  *(_DWORD *)(a3 + 200));
                if ( v51 && *(_DWORD *)(v51 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v51 + 32),
                    "[E][%s] Error recycling buffer for chan:%d\n",
                    "parse_xfer_event",
                    *(_DWORD *)(a3 + 200));
                kfree(*(_QWORD *)(v28 + 24));
              }
            }
            raw_read_lock_bh(a3 + 368);
          }
          while ( v16 != v19 );
        }
      }
    }
  }
  v48 = a3 + 368;
  if ( v7 < 5 )
    result = raw_read_unlock_bh(v48);
  else
    result = raw_write_unlock_irqrestore(v48, v53);
  _ReadStatusReg(SP_EL0);
  return result;
}
