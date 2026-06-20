__int64 __fastcall perfmon_counter_configure_store(__int64 a1, __int64 a2, char *a3, __int64 a4)
{
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned int v9; // w23
  char *v10; // x0
  unsigned __int8 v11; // w27
  const char *v12; // x24
  size_t v13; // x0
  unsigned __int64 v14; // x22
  char v15; // w8
  char *v16; // x0
  char *v17; // x0
  char *v18; // x24
  char *v19; // x0
  int v20; // w3
  __int64 v21; // x8
  __int64 v22; // x8
  int v23; // w4
  char v24; // w9
  __int64 v25; // x8
  __int64 v26; // x26
  __int64 v27; // x1
  unsigned __int8 v28; // w24
  __int64 v29; // x0
  __int64 v30; // x23
  _DWORD *v31; // x8
  unsigned int v32; // w0
  __int64 v33; // x1
  unsigned __int8 v34; // w8
  __int64 v35; // x0
  _DWORD *v36; // x9
  unsigned int v37; // w0
  __int64 v39; // x9
  void *v40; // x0
  char v41; // [xsp+Ch] [xbp-24h]
  __int64 v42; // [xsp+10h] [xbp-20h]
  unsigned __int16 v43[2]; // [xsp+18h] [xbp-18h] BYREF
  char v44[4]; // [xsp+1Ch] [xbp-14h] BYREF
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  stringp[0] = a3;
  v44[0] = 0;
  v43[0] = 0;
  mutex_lock(v6 + 136);
  if ( *(_BYTE *)(v6 + 131) == 1 )
  {
    dev_err(a1, "CNTR_CFG_ERR: Can't configure counters while PERFMON is running.\n");
LABEL_52:
    v26 = -22;
    goto LABEL_49;
  }
  v7 = *(_QWORD *)(v6 + 112);
  v8 = *(unsigned __int8 *)(v6 + 133);
  if ( (unsigned int)v8 >= *(unsigned __int8 *)(v7 + 5) )
  {
    dev_err(a1, "CNTR_CFG_ERR: No. of configured counters exceeds maximum limit.\n");
    goto LABEL_52;
  }
  v9 = *(unsigned __int8 *)(v7 + 4);
  v42 = a4;
  v10 = strsep(stringp, " ");
  v11 = v8;
  if ( v10 )
  {
    v12 = v10;
    v13 = strlen(v10);
    v14 = v13;
    if ( v13 < 7 )
    {
      v15 = 0;
      goto LABEL_15;
    }
    if ( v13 != 7 )
    {
      dev_err(a1, "CNTR_CFG_ERR: Invalid filter, %s\n", "remove and try again.");
      goto LABEL_62;
    }
    if ( (sysfs_streq(v12, "FILTER0") & 1) != 0 )
    {
      v9 = 0;
    }
    else
    {
      if ( (sysfs_streq(v12, "FILTER1") & 1) == 0 )
      {
        dev_err(a1, "CNTR_CFG_ERR: Wrong filter %s, %s\n", v12, "remove and try again.");
        goto LABEL_62;
      }
      v9 = 1;
    }
    if ( !*(_WORD *)(*(_QWORD *)(v6 + 64) + 2LL * v9) )
    {
      dev_err(a1, "CNTR_CFG_ERR: FILTER%u is not configured try again\n", v9);
      goto LABEL_62;
    }
    v16 = strsep(stringp, " ");
    v11 = v8;
    if ( v16 )
    {
      v12 = v16;
      v15 = 0x80;
LABEL_15:
      v11 = v8;
      v41 = v15 | v9 & 0x7F;
      while ( v11 != *(unsigned __int8 *)(*(_QWORD *)(v6 + 112) + 5LL) )
      {
        if ( (unsigned int)kstrtou8(v12, 0, v44) )
        {
          dev_err(a1, "CNTR_CFG_ERR: Invalid port %s, try again.\n", v12);
          goto LABEL_62;
        }
        if ( ((*(unsigned __int16 *)(*(_QWORD *)(v6 + 112) + 8LL) >> v44[0]) & 1) == 0 )
        {
          dev_err(a1, "CNTR_CFG_ERR: port %u not registered, try again.\n", (unsigned __int8)v44[0]);
          goto LABEL_62;
        }
        v17 = strsep(stringp, " ");
        if ( !v17 )
          goto LABEL_27;
        v18 = v17;
        if ( (unsigned int)kstrtou16(v17, 0, v43) )
        {
          dev_err(a1, "CNTR_CFG_ERR: Invalid event %s, try again.\n", v18);
          goto LABEL_62;
        }
        if ( v43[0] >= 0xFFu )
        {
          dev_err(a1, "CNTR_CFG_ERR: Unsupported event %u, try again.\n", v43[0]);
          goto LABEL_62;
        }
        v19 = strsep(stringp, " ");
        v20 = (unsigned __int8)v44[0];
        v21 = 3LL * v11;
        v12 = v19;
        *(_BYTE *)(*(_QWORD *)(v6 + 72) + v21) = v44[0];
        *(_WORD *)(*(_QWORD *)(v6 + 72) + v21 + 1) = v43[0];
        v22 = *(_QWORD *)(v6 + 32);
        *(_BYTE *)(v22 + 1) = v20;
        v23 = v43[0];
        *(_BYTE *)v22 = 0;
        *(_WORD *)(v22 + 2) = v23;
        if ( v14 >= 7 && ((*(unsigned __int16 *)(*(_QWORD *)(v6 + 64) + 2LL * v9) >> v44[0]) & 1) != 0 )
        {
          *(_BYTE *)v22 = v41;
          dev_info(a1, "Cntr %02u: port %u, event %03u FILTER%u configured.\n", v11, v20, v23, v9 & 0x7F);
        }
        else
        {
          dev_info(a1, "Cntr %02u: port %u event %03u configured.\n", v11, v20, v23);
        }
        ++v11;
        v24 = *(_BYTE *)(v6 + 134) + 4;
        *(_QWORD *)(v6 + 32) += 4LL;
        *(_BYTE *)(v6 + 134) = v24;
        if ( !v12 )
          goto LABEL_27;
      }
      dev_err(a1, "No. of cntrs exceeds max limit, skipping next config.\n");
      if ( v11 )
        goto LABEL_28;
      goto LABEL_61;
    }
  }
LABEL_27:
  if ( v11 )
  {
LABEL_28:
    v25 = *(_QWORD *)(v6 + 112);
    *(_BYTE *)(v6 + 133) = v11;
    if ( *(unsigned __int8 *)(v25 + 5) > (unsigned int)v11 )
    {
      *(_BYTE *)(*(_QWORD *)(v6 + 72) + 3LL * v11) = -1;
      *(_WORD *)(*(_QWORD *)(v6 + 72) + 3LL * *(unsigned __int8 *)(v6 + 133) + 1) = -1;
    }
    v26 = v42;
    if ( *(_BYTE *)(v6 + 128) == 1 && (*(_BYTE *)(v6 + 129) & 1) == 0 )
    {
      v27 = *(_QWORD *)(v6 + 8);
      v28 = *(_BYTE *)(v6 + 130);
      *(_QWORD *)(v6 + 16) = v27;
      while ( 1 )
      {
        v29 = *(_QWORD *)(v6 + 88);
        if ( v28 >= 0x64u )
          v30 = 100;
        else
          v30 = v28;
        v31 = **(_DWORD ***)(v6 + 96);
        if ( *(v31 - 1) != 1737159351 )
          __break(0x8228u);
        v32 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))v31)(
                v29,
                v27,
                0x534C432D50455246LL,
                0,
                v30);
        if ( v32 )
          break;
        v28 -= v30;
        v27 = *(_QWORD *)(v6 + 16) + v30;
        *(_QWORD *)(v6 + 16) = v27;
        if ( !v28 )
        {
          *(_BYTE *)(v6 + 129) = 1;
          goto LABEL_41;
        }
      }
      dev_err(a1, "Send SCMI: attr %d err: %d, %s\n", 0, v32, "remove and try again.");
      goto LABEL_58;
    }
LABEL_41:
    v33 = *(_QWORD *)(v6 + 24);
    if ( (_DWORD)v8 )
    {
      v33 += 4 * v8;
      v34 = 4 * (*(_BYTE *)(v6 + 133) - v8);
      if ( !v34 )
        goto LABEL_48;
    }
    else
    {
      v34 = *(_BYTE *)(v6 + 134);
      if ( !v34 )
        goto LABEL_48;
    }
    v35 = *(_QWORD *)(v6 + 88);
    v36 = **(_DWORD ***)(v6 + 96);
    if ( *(v36 - 1) != 1737159351 )
      __break(0x8229u);
    v37 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v36)(
            v35,
            v33,
            0x534C432D50455246LL,
            1,
            v34);
    if ( v37 )
    {
      dev_err(a1, "Send SCMI: attr %d err: %d, %s\n", 1, v37, "remove and try again.");
LABEL_58:
      v26 = -22;
      goto LABEL_49;
    }
LABEL_48:
    *(_BYTE *)(v6 + 132) = 1;
    goto LABEL_49;
  }
LABEL_61:
  dev_err(a1, "CNTR_CFG_ERR: Port/Event not provided.\n");
LABEL_62:
  cntr_payload_cleanup(v6);
  if ( *(_BYTE *)(v6 + 128) == 1 )
  {
    memset(*(void **)(v6 + 8), 0, *(unsigned int *)(v6 + 44));
    v39 = *(_QWORD *)(v6 + 112);
    v40 = *(void **)(v6 + 64);
    *(_QWORD *)(v6 + 16) = *(_QWORD *)(v6 + 8);
    memset(v40, 0, 2LL * *(unsigned __int8 *)(v39 + 4));
    v26 = -22;
    *(_WORD *)(v6 + 128) = 0;
    *(_BYTE *)(v6 + 130) = 0;
  }
  else
  {
    v26 = -22;
  }
LABEL_49:
  mutex_unlock(v6 + 136);
  _ReadStatusReg(SP_EL0);
  return v26;
}
