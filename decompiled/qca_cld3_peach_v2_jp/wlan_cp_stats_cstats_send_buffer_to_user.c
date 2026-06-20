__int64 __fastcall wlan_cp_stats_cstats_send_buffer_to_user(unsigned int a1)
{
  unsigned int v1; // w19
  char *v2; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  int v14; // w8
  char *v15; // x8
  char *v16; // x24
  __int64 v17; // x21
  __int64 v18; // x22
  char *v19; // x26
  unsigned __int64 v20; // x23
  char *v21; // x27
  __int64 v22; // x8
  __int64 v23; // x8
  int v24; // w28
  __int64 v25; // x19
  void *v26; // x8
  __int64 v27; // x3
  __int64 v28; // x8
  const char *v29; // x2
  __int64 v30; // x4
  unsigned __int8 v31; // w0
  __int64 v32; // x21
  _DWORD *v33; // x8
  char *v35; // [xsp+8h] [xbp-C8h]
  unsigned __int64 v36; // [xsp+10h] [xbp-C0h]
  int v37; // [xsp+1Ch] [xbp-B4h]
  __int64 v38; // [xsp+20h] [xbp-B0h]
  __int64 v39; // [xsp+28h] [xbp-A8h]
  _QWORD *v40; // [xsp+30h] [xbp-A0h]
  unsigned int v41; // [xsp+3Ch] [xbp-94h]
  unsigned __int64 v42; // [xsp+40h] [xbp-90h]
  char *v43; // [xsp+48h] [xbp-88h]
  unsigned __int64 v44; // [xsp+50h] [xbp-80h]
  __int64 v45; // [xsp+58h] [xbp-78h] BYREF
  _QWORD v46[11]; // [xsp+60h] [xbp-70h] BYREF
  int v47; // [xsp+B8h] [xbp-18h]
  __int64 v48; // [xsp+C0h] [xbp-10h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( byte_85CAD0 != 1 )
  {
    v13 = 0;
    goto LABEL_66;
  }
  v1 = a1;
  if ( a1 >= 3 )
    goto LABEL_69;
  v2 = (char *)&cstats + 16 * a1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 96);
  }
  else
  {
    raw_spin_lock_bh(v2 + 96);
    *((_QWORD *)v2 + 13) |= 1uLL;
  }
  wlan_cp_stats_get_cstats_free_node(v1);
  v4 = *((_QWORD *)v2 + 13);
  if ( (v4 & 1) != 0 )
  {
    *((_QWORD *)v2 + 13) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 96);
    if ( v1 )
      goto LABEL_9;
  }
  else
  {
    raw_spin_unlock(v2 + 96);
    if ( v1 )
    {
LABEL_9:
      v13 = -1;
      v14 = 4;
      goto LABEL_10;
    }
  }
  v45 = 0x485F534300000000LL;
  v46[0] = 19795;
  v47 = 0;
  memset(&v46[1], 0, 80);
  scnprintf(
    (char *)v46 + 2,
    84,
    "[%s : %d, %s : %d, %s : %d]",
    "Chispet stats - hdr_version",
    1,
    "Endianness",
    0,
    "Drop cnt",
    dword_85CAA8);
  v32 = v31;
  if ( v31 >= 0x5Bu || (qdf_mem_copy((char *)&v45 + (unsigned int)v31 + 10, "CS_HEM", 6u), (unsigned int)v32 > 0x53) )
LABEL_69:
    __break(0x5512u);
  v33 = off_85CAC8;
  *((_BYTE *)v46 + v32 + 8) = 0;
  if ( !v33 )
  {
    v13 = -1;
LABEL_65:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: failed to send version info",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_cp_stats_cstats_send_version_to_usr");
    goto LABEL_66;
  }
  if ( *(v33 - 1) != -1699339192 )
    __break(0x8228u);
  v13 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD, _QWORD))v33)(&v45, v32 + 16, 0, 0);
  if ( v13 )
    goto LABEL_65;
  v14 = 16;
LABEL_10:
  v37 = v14;
  v15 = (char *)&cstats + 24 * v1;
  v16 = *((char **)v15 + 6);
  v43 = v15 + 48;
  if ( v16 != v15 + 48 )
  {
    v17 = 0;
    v39 = v1 == 0;
    v18 = 0;
    v42 = v1 | 0xA8LL;
    v38 = v1 == 1;
    v19 = (char *)&cstats + v1;
    v41 = v1;
    v40 = (_QWORD *)((char *)&cstats + 24 * v1);
    v20 = 1;
    v35 = (char *)&cstats + 4 * v1;
    v36 = (4LL * v1) | 0x90;
    v44 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v21 = *(char **)v16;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v44 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v44 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v2 + 96);
        if ( v1 )
          goto LABEL_18;
      }
      else
      {
        raw_spin_lock_bh(v2 + 96);
        *((_QWORD *)v2 + 13) |= 1uLL;
        if ( v1 )
        {
LABEL_18:
          if ( v1 == 2 )
            goto LABEL_69;
          goto LABEL_23;
        }
      }
      qdf_mem_copy(v16 + 32, "CS_HSM", 6u);
      v22 = *((unsigned int *)v16 + 6);
      if ( (unsigned int)v22 > 0x7F6 )
        goto LABEL_69;
      qdf_mem_copy(&v16[v22 + 38], "CS_HEM", 6u);
LABEL_23:
      if ( v42 > 0xC0 )
        goto LABEL_68;
      if ( (v19[168] & 1) == 0 )
        qdf_list_remove_node((__int64)v40, v16);
      v23 = *((_QWORD *)v2 + 13);
      if ( (v23 & 1) != 0 )
      {
        *((_QWORD *)v2 + 13) = v23 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v2 + 96);
      }
      else
      {
        raw_spin_unlock(v2 + 96);
      }
      v24 = *((_DWORD *)v16 + 6);
      if ( qword_85CAB8 )
      {
        if ( !(v20 % qword_85CAB8) )
        {
          v25 = (unsigned int)qword_85CAB0;
          if ( (_DWORD)qword_85CAB0 )
          {
            do
            {
              --v25;
              _const_udelay(4295000);
            }
            while ( v25 );
          }
        }
      }
      v1 = v41;
      v26 = off_85CAC8;
      if ( off_85CAC8 )
      {
        v27 = (unsigned __int8)byte_85CAD1;
        if ( *((_DWORD *)off_85CAC8 - 1) != -1699339192 )
          __break(0x8228u);
        v13 = ((__int64 (__fastcall *)(char *, _QWORD, _QWORD, __int64))v26)(
                v16 + 28,
                (unsigned int)(v37 + v24),
                v41,
                v27);
      }
      if ( v13 )
      {
        if ( v36 > 0xC0 )
        {
LABEL_68:
          __break(1u);
          goto LABEL_69;
        }
        ++*((_DWORD *)v35 + 36);
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Send Failed %d drop_count = %u",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "wlan_cp_stats_cstats_send_buffer_to_user",
          v13);
      }
      if ( (v19[168] & 1) == 0 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v44 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v44 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v2 + 96);
        }
        else
        {
          raw_spin_lock_bh(v2 + 96);
          *((_QWORD *)v2 + 13) |= 1uLL;
        }
        qdf_list_insert_back(v40, v16);
        v28 = *((_QWORD *)v2 + 13);
        if ( (v28 & 1) != 0 )
        {
          *((_QWORD *)v2 + 13) = v28 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v2 + 96);
        }
        else
        {
          raw_spin_unlock(v2 + 96);
        }
      }
      ++v20;
      v16 = v21;
      v17 += v39;
      v18 += v38;
      if ( v21 == v43 )
        goto LABEL_50;
    }
  }
  v18 = 0;
  v17 = 0;
LABEL_50:
  if ( byte_85CAD1 == 1 )
  {
    if ( v1 == 1 )
    {
      v29 = "%s: FW List len : %zu";
      v30 = v18;
LABEL_55:
      qdf_trace_msg(0x38u, 8u, v29, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_cp_stats_cstats_send_buffer_to_user", v30);
      goto LABEL_66;
    }
    if ( !v1 )
    {
      v29 = "%s: HOST List len : %zu";
      v30 = v17;
      goto LABEL_55;
    }
  }
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return v13;
}
