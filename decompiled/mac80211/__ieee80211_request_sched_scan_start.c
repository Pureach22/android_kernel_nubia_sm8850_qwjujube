__int64 __fastcall _ieee80211_request_sched_scan_start(unsigned __int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  _QWORD *v4; // x8
  unsigned int v7; // w23
  unsigned int v8; // w24
  __int64 v9; // x10
  int v10; // w8
  int v11; // w9
  unsigned int v12; // w25
  int v13; // w26
  __int64 v14; // x22
  __int64 v15; // x4
  __int64 v16; // x5
  int v17; // w0
  __int64 result; // x0
  __int64 v19; // x9
  unsigned __int64 v20; // x1
  _DWORD *v21; // x8
  unsigned int v22; // w20
  _QWORD v23[4]; // [xsp+18h] [xbp-B8h] BYREF
  __int64 v24; // [xsp+38h] [xbp-98h] BYREF
  __int64 v25; // [xsp+40h] [xbp-90h]
  __int64 v26; // [xsp+48h] [xbp-88h]
  _QWORD v27[16]; // [xsp+50h] [xbp-80h] BYREF

  v27[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1616);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 464) + 200LL);
  memset(v27, 0, 112);
  v25 = 0;
  v26 = 0;
  v24 = 0;
  if ( v3 )
  {
    v4 = *(_QWORD **)(v2 + 72);
    if ( v4[41] )
    {
      v7 = 1;
      LODWORD(v24) = -1;
      if ( v4[42] )
        goto LABEL_4;
    }
    else
    {
      v7 = 0;
      if ( v4[42] )
      {
LABEL_4:
        v8 = v7 + 1;
        v7 |= 2u;
        HIDWORD(v24) = -1;
        if ( !v4[43] )
          goto LABEL_6;
        goto LABEL_5;
      }
    }
    v8 = v7;
    if ( !v4[43] )
    {
LABEL_6:
      if ( v4[44] )
      {
        v7 |= 8u;
        ++v8;
        HIDWORD(v25) = -1;
      }
      if ( v4[45] )
      {
        v7 |= 0x10u;
        ++v8;
        LODWORD(v26) = -1;
      }
      v9 = v4[46];
      v10 = *(_DWORD *)(v2 + 4808);
      v11 = *(_DWORD *)(a2 + 32);
      if ( v9 )
      {
        v7 |= 0x20u;
        ++v8;
        HIDWORD(v26) = -1;
      }
      v12 = *(_DWORD *)(a2 + 40);
      v13 = v10 + v11;
      if ( !is_mul_ok(v10 + v11, v8) || (v14 = _kmalloc_noprof((int)v8 * (__int64)v13, 3520)) == 0 )
      {
        result = 4294967284LL;
LABEL_33:
        *(_QWORD *)(v2 + 4856) = 0;
        *(_QWORD *)(v2 + 4864) = 0;
        goto LABEL_34;
      }
      v15 = *(_QWORD *)(a2 + 24);
      v16 = *(_QWORD *)(a2 + 32);
      memset(v23, 0, sizeof(v23));
      v17 = ieee80211_build_preq_ies(a1, v14, (int)(v8 * v13), v27, v15, v16, v7, &v24, v23, (v12 >> 11) & 2);
      if ( v17 < 0 )
      {
LABEL_32:
        v22 = v17;
        kfree(v14);
        result = v22;
        goto LABEL_33;
      }
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 1616) + 1471LL) & 1) != 0
        || (*(_DWORD *)(a1 + 1624) & 0x20) != 0
        || (drv_sched_scan_start___already_done & 1) != 0 )
      {
        if ( (*(_BYTE *)(a1 + 1624) & 0x20) == 0 )
        {
LABEL_19:
          v17 = -5;
          goto LABEL_32;
        }
      }
      else
      {
        v19 = *(_QWORD *)(a1 + 1608);
        drv_sched_scan_start___already_done = 1;
        if ( v19 )
          v20 = v19 + 296;
        else
          v20 = a1 + 1640;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v20);
        __break(0x800u);
        if ( (*(_BYTE *)(a1 + 1624) & 0x20) == 0 )
          goto LABEL_19;
      }
      v21 = *(_DWORD **)(*(_QWORD *)(v2 + 464) + 200LL);
      if ( *(v21 - 1) != 1035354395 )
        __break(0x8228u);
      v17 = ((__int64 (__fastcall *)(__int64, unsigned __int64, unsigned __int64, _QWORD *))v21)(v2, a1 + 4720, a2, v27);
      if ( !v17 )
      {
        atomic_store(a1, (unsigned __int64 *)(v2 + 4856));
        atomic_store(a2, (unsigned __int64 *)(v2 + 4864));
        kfree(v14);
        result = 0;
        goto LABEL_34;
      }
      goto LABEL_32;
    }
LABEL_5:
    v7 |= 4u;
    ++v8;
    LODWORD(v25) = -1;
    goto LABEL_6;
  }
  result = 4294967201LL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
