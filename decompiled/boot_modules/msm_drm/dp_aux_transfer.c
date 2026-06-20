__int64 __fastcall dp_aux_transfer(__int64 a1, int *a2)
{
  __int64 v2; // x19
  __int64 v5; // x21
  char v6; // w9
  __int64 v7; // x0
  unsigned __int64 v8; // x4
  unsigned __int8 *v9; // x8
  int v10; // w9
  bool v11; // cc
  int v12; // w10
  int v13; // w9
  int v14; // w8
  int v15; // w8
  int *v16; // x23
  int v17; // w10
  unsigned int v18; // w8
  char v19; // w8
  int v20; // w0
  char v21; // w8
  int v22; // w8
  void (*v23)(void); // x8
  void (*v24)(void); // x8
  __int64 v25; // x27
  void (*v26)(void); // x8
  void (*v27)(void); // x8
  __int64 v28; // x28
  void (*v29)(void); // x8
  __int64 v30; // x22
  unsigned __int64 StatusReg; // x23
  __int64 (*v32)(void); // x8
  __int64 v33; // x0
  __int64 v35; // [xsp+0h] [xbp-20h] BYREF
  __int64 v36; // [xsp+8h] [xbp-18h]
  __int64 v37; // [xsp+10h] [xbp-10h]
  __int64 v38; // [xsp+18h] [xbp-8h]

  v2 = a1 - 80;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 - 80);
  if ( *(_DWORD *)(a1 + 1608) )
  {
    v5 = -110;
  }
  else
  {
    v6 = *((_BYTE *)a2 + 4);
    v7 = a1 - 232;
    *(_BYTE *)(a1 + 1579) = (v6 & 8) != 0;
    v8 = *((_QWORD *)a2 + 2);
    if ( v8 && (v9 = *((unsigned __int8 **)a2 + 1)) != nullptr )
    {
      v10 = v6 & 8;
      if ( v10 )
        v11 = v8 > 0x10;
      else
        v11 = 0;
      v12 = v11;
      if ( v8 > 0x80 || v12 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 - 208),
          "[e][%-4d]%s: invalid msg: size(%zu), request(%x)\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          "dp_aux_transfer_ready",
          v8,
          *((unsigned __int8 *)a2 + 4));
        printk(&unk_21FA06, "dp_aux_transfer_ready");
        v5 = -22;
        goto LABEL_60;
      }
      if ( (v10 & 8) == 0 && (a2[1] & 1) == 0 )
      {
        v13 = *a2;
        if ( *a2 == 80 || v13 == 48 )
        {
          v14 = *v9;
          if ( v13 == 48 )
            *(_DWORD *)(a1 + 1588) = v14;
          else
            *(_DWORD *)(a1 + 1584) = v14;
        }
      }
      if ( (~*((unsigned __int8 *)a2 + 4) & 5) == 0 && *((_QWORD *)a2 + 2) )
      {
        v15 = *(_DWORD *)(a1 + 1584);
        v16 = (int *)(a1 + 1584);
        if ( (v15 & 0x7F) != 0 )
        {
          v17 = *(_DWORD *)(a1 + 1588);
          *(_WORD *)(a1 + 1580) = 256;
          *(_BYTE *)(a1 + 1578) = 1;
          *(_BYTE *)(a1 + 1582) = 1;
          if ( v17 )
          {
            v35 = 48;
            v36 = a1 + 1588;
            v37 = 1;
            dp_aux_cmd_fifo_tx(v7, &v35);
          }
          v18 = *a2;
          v36 = a1 + 1584;
          v35 = v18;
          v37 = 1;
          dp_aux_cmd_fifo_tx(a1 - 232, &v35);
          v15 = *v16;
          v7 = a1 - 232;
        }
        *v16 = v15 + 16;
        if ( (v15 | 0x80) == 0xF0 )
          *(_DWORD *)(a1 + 1588) = 0;
      }
      v19 = *((_BYTE *)a2 + 4);
      *(_BYTE *)(a1 + 1581) = 1;
      v19 &= 1u;
      *(_BYTE *)(a1 + 1578) = 1;
      *(_BYTE *)(a1 + 1580) = v19;
      *(_BYTE *)(a1 + 1582) = v19 ^ 1;
    }
    else
    {
      *((_BYTE *)a2 + 5) = 0;
      if ( (*(_BYTE *)(a1 + 1578) & 1) == 0 )
      {
        v5 = *((_QWORD *)a2 + 2);
        goto LABEL_60;
      }
    }
    v20 = dp_aux_cmd_fifo_tx(v7, a2);
    if ( v20 < 0 )
    {
      v5 = v20;
      if ( !*(_DWORD *)(a1 + 1608) )
      {
        v22 = *(_DWORD *)(a1 + 1596) + 1;
        *(_DWORD *)(a1 + 1596) = v22;
        if ( (unsigned int)(-858993459 * v22) <= 0x33333333 )
        {
          v23 = *(void (**)(void))(*(_QWORD *)(a1 - 104) + 56LL);
          if ( *((_DWORD *)v23 - 1) != -3400336 )
            __break(0x8228u);
          v23();
        }
        v24 = *(void (**)(void))(*(_QWORD *)(a1 - 104) + 40LL);
        if ( *((_DWORD *)v24 - 1) != -1040530234 )
          __break(0x8228u);
        v24();
      }
    }
    else
    {
      if ( *(_DWORD *)(a1 + 1592) )
      {
        if ( *(_BYTE *)(a1 + 1579) )
          v21 = 2;
        else
          v21 = 8;
      }
      else
      {
        if ( *(_BYTE *)(a1 + 1580) == 1 )
        {
          v25 = *((_QWORD *)a2 + 2);
          v26 = *(void (**)(void))(*(_QWORD *)(a1 - 104) + 32LL);
          if ( *((_DWORD *)v26 - 1) != 1710788455 )
            __break(0x8228u);
          v26();
          **(_DWORD **)(a1 - 104) = -2147483647;
          v27 = *(void (**)(void))(*(_QWORD *)(a1 - 104) + 16LL);
          if ( *((_DWORD *)v27 - 1) != -52717133 )
            __break(0x8228u);
          v27();
          v28 = *((_QWORD *)a2 + 1);
          v29 = *(void (**)(void))(*(_QWORD *)(a1 - 104) + 8LL);
          if ( *((_DWORD *)v29 - 1) != -1578297700 )
            __break(0x8228u);
          v29();
          if ( (_DWORD)v25 )
          {
            v30 = 0;
            StatusReg = _ReadStatusReg(SP_EL0);
            do
            {
              v32 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 104) + 8LL);
              if ( *((_DWORD *)v32 - 1) != -1578297700 )
                __break(0x8228u);
              v33 = v32();
              *(_BYTE *)(v28 + v30) = BYTE1(v33);
              if ( (_DWORD)v30 != BYTE2(v33) )
              {
                ipc_log_string(
                  *(_QWORD *)(a1 - 208),
                  "[w][%-4d]Index mismatch: expected %d, found %d\n",
                  *(_DWORD *)(StatusReg + 1800),
                  v30,
                  BYTE2(v33));
                printk(&unk_261091, "dp_aux_cmd_fifo_rx");
              }
              ++v30;
            }
            while ( (_DWORD)v25 != (_DWORD)v30 );
          }
        }
        dp_aux_hex_dump(a1, a2);
        v21 = 0;
      }
      *((_BYTE *)a2 + 5) = v21;
      v5 = *((_QWORD *)a2 + 2);
      *(_DWORD *)(a1 + 1596) = 0;
    }
  }
LABEL_60:
  *(_BYTE *)(a1 + 1578) = 0;
  mutex_unlock(v2);
  _ReadStatusReg(SP_EL0);
  return v5;
}
