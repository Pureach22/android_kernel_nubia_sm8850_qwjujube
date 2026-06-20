// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall fastrpc_invoke_send(int a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x9
  unsigned __int64 StatusReg; // x23
  __int64 v6; // x19
  __int64 v7; // x20
  unsigned int v8; // w8
  int v9; // w8
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x9
  int v13; // w10
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  unsigned int v16; // w21
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x1
  unsigned __int64 v20; // x22
  __int64 v21; // x0
  __int64 v22; // x9
  unsigned int v23; // w10
  unsigned int v24; // w11
  __int64 v25; // x12
  __int64 v26; // x13
  unsigned int v27; // w8
  __int64 v28; // x9
  unsigned int v29; // w8
  __int64 v30; // x9
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x12
  __int64 v34; // x13
  __int64 v36; // x24
  __int64 (__fastcall *v37)(__int64, _QWORD, unsigned __int64, __int64, _QWORD, _QWORD, __int64, __int64); // x8
  __int64 v38; // x0
  __int64 v39; // t1
  __int64 v40; // [xsp+8h] [xbp-28h]
  unsigned int v41; // [xsp+10h] [xbp-20h]
  unsigned int v42; // [xsp+14h] [xbp-1Ch]
  __int64 v43; // [xsp+18h] [xbp-18h]
  unsigned int v44; // [xsp+24h] [xbp-Ch]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v4 = *(_QWORD *)(a2 + 184);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_QWORD *)(v4 + 128);
  *(_DWORD *)(a2 + 144) = *(_DWORD *)(v4 + 244);
  v7 = a2 + 144;
  v8 = *(_DWORD *)(StatusReg + 1800);
  *(_DWORD *)(a2 + 148) = v8;
  if ( a1 )
  {
    if ( v8 >> 26 )
    {
      dev_err(
        *(_QWORD *)(*(_QWORD *)(v4 + 128) + 168LL),
        "Error: %s: priority bits in tid %d are non-zero (prio %u)",
        "fastrpc_invoke_send",
        v8,
        a1);
      return (unsigned int)-14;
    }
    *(_DWORD *)(a2 + 148) = v8 | (a1 << 26);
  }
  if ( a3 == 1 )
    *(_DWORD *)v7 = 0;
  v9 = *(_DWORD *)(v4 + 268);
  v10 = 1;
  if ( v9 == 3 )
    v10 = 2;
  if ( v9 == 1 )
    v11 = 0;
  else
    v11 = v10;
  v12 = v11 | *(_QWORD *)(a2 + 80);
  v13 = *(_DWORD *)(a2 + 36);
  v14 = *(_QWORD *)(a2 + 216);
  *(_QWORD *)(a2 + 152) = v12;
  *(_DWORD *)(a2 + 160) = a4;
  *(_DWORD *)(a2 + 164) = v13;
  if ( v14 )
    v14 = *(_QWORD *)(v14 + 64);
  v15 = (*(_QWORD *)(a2 + 88) + 4095LL) & 0xFFFFFFFFFFFFF000LL;
  *(_QWORD *)(a2 + 168) = v14;
  *(_QWORD *)(a2 + 176) = v15;
  v16 = fastrpc_transport_send(v6, a2 + 144, 40);
  while ( 1 )
  {
    v17 = ktime_get_with_offset(1);
    v18 = ns_to_timespec64(v17);
    if ( v18 <= 0x225C17D03LL )
      v20 = v18 >= (__int64)0xFFFFFFFDDA3E82FDLL ? v19 + 1000000000 * v18 : 0x8000000000000000LL;
    else
      v20 = 0x7FFFFFFFFFFFFFFFLL;
    v21 = raw_spin_lock_irqsave(v6 + 64032);
    v27 = *(_DWORD *)(v6 + 52760);
    if ( v27 < 0x81 )
      break;
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)loc_CE40 >> 3) & 0x1FFFFFF8)) >> loc_CE40) & 1) != 0 )
    {
      v43 = v26;
      v40 = v25;
      v44 = v24;
      v41 = v23;
      v45 = v22;
      v42 = v27;
      ++loc_CE28;
      v36 = qword_22650;
      if ( qword_22650 )
      {
        do
        {
          v37 = *(__int64 (__fastcall **)(__int64, _QWORD, unsigned __int64, __int64, _QWORD, _QWORD, __int64, __int64))v36;
          v38 = *(_QWORD *)(v36 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v36 - 4LL) != -1468097945 )
            __break(0x8228u);
          v21 = v37(v38, v42, v20, v45, v41, v44, v40, v43);
          v39 = *(_QWORD *)(v36 + 24);
          v36 += 24;
        }
        while ( v39 );
      }
      --loc_CE28;
      if ( loc_CE28 <= 1u )
        preempt_schedule_notrace(v21);
    }
  }
  v28 = v6 + 56LL * v27;
  if ( v27 <= 0x7E )
    v29 = v27 + 1;
  else
    v29 = 0;
  v30 = v28 + 52768;
  *(_QWORD *)v30 = *(_QWORD *)v7;
  v31 = *(_QWORD *)(v7 + 8);
  v32 = *(_QWORD *)(v7 + 16);
  v33 = *(_QWORD *)(v7 + 24);
  v34 = *(_QWORD *)(v7 + 32);
  *(_DWORD *)(v30 + 40) = v16;
  *(_QWORD *)(v30 + 48) = v20;
  *(_QWORD *)(v30 + 8) = v31;
  *(_QWORD *)(v30 + 16) = v32;
  *(_QWORD *)(v30 + 24) = v33;
  *(_QWORD *)(v30 + 32) = v34;
  *(_DWORD *)(v6 + 52760) = v29;
  raw_spin_unlock_irqrestore(v6 + 64032, v21);
  return v16;
}
