__int64 __fastcall qcom_smp2p_intr(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x1
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  __int64 v7; // x22
  __int64 v8; // x22
  int v9; // t1
  int v10; // w8
  int v11; // w4
  __int64 v12; // x0
  int v13; // w3
  __int64 v14; // x21
  __int64 *v15; // x9
  unsigned int v16; // w20
  signed int v17; // w22
  _QWORD *v18; // x26
  _QWORD *v19; // x27
  __int64 v20; // x9
  const char *v21; // x1
  __int64 *j; // x28
  unsigned int v23; // w0
  int v24; // w8
  unsigned int v25; // w23
  __int64 v26; // x24
  char v27; // w8
  __int64 v28; // x22
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x23
  __int64 v38; // x26
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x20
  int v42; // w8
  int v43; // w8
  __int64 v44; // x0
  int v46; // [xsp+4h] [xbp-2Ch]
  __int64 v47; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v48; // [xsp+14h] [xbp-1Ch] BYREF
  char s1[8]; // [xsp+18h] [xbp-18h] BYREF
  __int64 i; // [xsp+20h] [xbp-10h]
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 8);
  v4 = *(unsigned int *)(a2 + 24);
  v5 = *(unsigned int *)(a2 + 52);
  v47 = 0;
  if ( v3 )
  {
    if ( (*(_BYTE *)(a2 + 38) & 1) != 0 )
      goto LABEL_11;
    goto LABEL_6;
  }
  v6 = qcom_smem_get(v5, v4, &v47);
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)a2, "Unable to acquire remote smp2p item\n");
    goto LABEL_56;
  }
  v3 = v6;
  *(_QWORD *)(a2 + 8) = v6;
  if ( (*(_BYTE *)(a2 + 38) & 1) == 0 )
  {
LABEL_6:
    v7 = *(_QWORD *)(a2 + 16);
    ipc_log_string(
      ilc,
      "[%s]: %d: version[%d:%d]\n",
      "qcom_smp2p_negotiate",
      *(_DWORD *)(a2 + 52),
      *(unsigned __int8 *)(v3 + 4),
      *(unsigned __int8 *)(v7 + 4));
    if ( *(unsigned __int8 *)(v3 + 4) == *(unsigned __int8 *)(v7 + 4) )
    {
      v9 = *(unsigned __int16 *)(v7 + 5);
      v8 = v7 + 5;
      v10 = (v9 | (*(unsigned __int8 *)(v8 + 2) << 16))
          & (*(unsigned __int16 *)(v3 + 5) | (*(unsigned __int8 *)(v3 + 7) << 16));
      *(_WORD *)v8 = v9 & *(_WORD *)(v3 + 5);
      *(_BYTE *)(v8 + 2) = BYTE2(v10);
      if ( (v10 & 1) != 0 )
      {
        v11 = 1;
        *(_BYTE *)(a2 + 36) = 1;
      }
      else
      {
        v11 = *(unsigned __int8 *)(a2 + 36);
      }
      v12 = ilc;
      v13 = *(_DWORD *)(a2 + 52);
      *(_BYTE *)(a2 + 38) = 1;
      ipc_log_string(v12, "[%s]: %d: state=open ssr_ack=%d\n", "qcom_smp2p_negotiate", v13, v11);
    }
  }
LABEL_11:
  if ( *(_BYTE *)(a2 + 38) == 1 )
  {
    v14 = *(_QWORD *)(a2 + 8);
    if ( *(_BYTE *)(a2 + 36) == 1 && (*(_DWORD *)(v14 + 16) & 1) != *(_BYTE *)(a2 + 37) )
    {
      if ( *(unsigned __int8 *)(v14 + 4) >= 2u )
      {
        v15 = *(__int64 **)(a2 + 144);
        if ( v15 != (__int64 *)(a2 + 144) )
        {
          do
          {
            if ( v15[4] )
              *((_DWORD *)v15 + 10) = 0;
            v15 = (__int64 *)*v15;
          }
          while ( v15 != (__int64 *)(a2 + 144) );
          v14 = *(_QWORD *)(a2 + 8);
        }
      }
      v46 = 1;
    }
    else
    {
      v46 = 0;
    }
    v16 = *(_DWORD *)(a2 + 32);
    v17 = *(unsigned __int16 *)(v14 + 14);
    *(_QWORD *)s1 = 0;
    for ( i = 0; (int)v16 < v17; ++v16 )
    {
      v18 = (_QWORD *)(v14 + 20 + 20LL * v16);
      v19 = (_QWORD *)(a2 + 144);
      while ( 1 )
      {
        v19 = (_QWORD *)*v19;
        if ( v19 == (_QWORD *)(a2 + 144) )
          break;
        if ( v16 >= 0x10 )
          __break(0x5512u);
        v20 = v18[1];
        v21 = (const char *)v19[3];
        *(_QWORD *)s1 = *v18;
        i = v20;
        if ( !strcmp(s1, v21) )
        {
          v19[4] = v18 + 2;
          v17 = *(unsigned __int16 *)(v14 + 14);
          break;
        }
      }
    }
    *(_DWORD *)(a2 + 32) = v16;
    ipc_log_string(
      ilc,
      "[%s]: %d: smp2p_num:%d in_num:%d\n",
      "qcom_smp2p_notify_in",
      *(_DWORD *)(a2 + 52),
      v16,
      *(unsigned __int16 *)(v14 + 14));
    for ( j = *(__int64 **)(a2 + 144); j != (__int64 *)(a2 + 144); j = (__int64 *)*j )
    {
      if ( j[4] )
      {
        v23 = readl();
        v24 = *((_DWORD *)j + 10);
        *((_DWORD *)j + 10) = v23;
        __dsb(0xFu);
        v25 = v23;
        v26 = j[8] | v24 ^ v23;
        ipc_log_string(
          ilc,
          "[%s]: %d:\t%s: status:%0lx val:%0x\n",
          "qcom_smp2p_notify_in",
          *(_DWORD *)(a2 + 52),
          (const char *)j[3],
          v26,
          v23);
        if ( v26 )
        {
          v27 = 0;
          v28 = v25;
          do
          {
            v36 = (unsigned int)v26 & (unsigned __int64)(-1LL << v27);
            if ( !v36 )
              break;
            v37 = __clz(__rbit64(v36));
            v38 = 1LL << v37;
            if ( ((1LL << v37) & v28) != 0 )
            {
              if ( (j[9] & v38) != 0 )
                goto LABEL_45;
            }
            else if ( (j[10] & v38) != 0 )
            {
LABEL_45:
              v39 = j[6];
              v48 = 0;
              if ( _irq_resolve_mapping(v39, v37, &v48) )
                v40 = v48;
              else
                v40 = 0;
              handle_nested_irq(v40);
              _X8 = (unsigned __int64 *)(j + 8);
              __asm { PRFM            #0x11, [X8] }
              do
                v35 = __ldxr(_X8);
              while ( __stxr(v35 & ~v38, _X8) );
            }
            v27 = v37 + 1;
          }
          while ( v37 < 0x1F );
        }
      }
      else
      {
        ipc_log_string(
          ilc,
          "[%s]: %d:\t%s: skipping not ready\n",
          "qcom_smp2p_notify_in",
          *(_DWORD *)(a2 + 52),
          (const char *)j[3]);
      }
    }
    if ( v46 )
    {
      v41 = *(_QWORD *)(a2 + 16);
      ipc_log_string(
        ilc,
        "[%s]: %d: SSR detected, doing SSR Handshake\n",
        "qcom_smp2p_do_ssr_ack",
        *(_DWORD *)(a2 + 52));
      v42 = *(unsigned __int8 *)(a2 + 37);
      *(_BYTE *)(a2 + 37) = v42 ^ 1;
      if ( v42 )
        v43 = 0;
      else
        v43 = 2;
      *(_DWORD *)(v41 + 16) = *(_DWORD *)(v41 + 16) & 0xFFFFFFFD | v43;
      __dsb(0xEu);
      v44 = *(_QWORD *)(a2 + 136);
      if ( v44 )
      {
        mbox_send_message(v44, 0);
        mbox_client_txdone(*(_QWORD *)(a2 + 136), 0);
      }
      else
      {
        regmap_write(*(_QWORD *)(a2 + 64), *(unsigned int *)(a2 + 72), 1LL << *(_DWORD *)(a2 + 76));
      }
    }
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return 1;
}
