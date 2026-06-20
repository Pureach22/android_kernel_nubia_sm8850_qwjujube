__int64 __fastcall msm_aer_print_error(__int64 result, __int64 *a2)
{
  int v3; // w10
  int v4; // w24
  int v5; // w23
  unsigned __int64 v6; // x8
  _BOOL4 v7; // w9
  __int64 v8; // x25
  int v9; // w11
  int v10; // w12
  bool v11; // zf
  __int64 v12; // x12
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x9
  __int64 v17; // x8
  int v18; // w12
  int v19; // w11
  __int64 v20; // x8
  const char *v21; // x21
  const char *v22; // x22
  __int64 v23; // x8
  __int64 v24; // x26
  char v25; // w8
  char **v26; // x28
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x24
  const char *v29; // x25
  const char *v30; // x6
  const char *v31; // x6
  _QWORD *v32; // x21
  unsigned int v33; // w8
  int v34; // w8
  int v35; // w8
  __int64 v36; // x20
  int i; // w8
  __int64 v38; // [xsp+0h] [xbp-20h]
  int v39; // [xsp+8h] [xbp-18h]
  _QWORD v40[2]; // [xsp+10h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_DWORD *)a2 + 14);
  v4 = *(_DWORD *)(result + 56);
  v5 = *(unsigned __int8 *)(*(_QWORD *)(result + 16) + 248LL);
  if ( !v3 )
  {
    if ( !*a2 )
      goto LABEL_71;
    v16 = *((_WORD *)a2 + 27) & 3;
    if ( (_DWORD)v16 != 3 )
    {
      ipc_log_string(
        *(_QWORD *)(*a2 + 1704),
        "DBG1:%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=Inaccessible, (Unregistered Agent ID)\n",
        "msm_aer_print_error",
        *(_DWORD *)(*a2 + 1348),
        aer_error_severity_string[v16]);
      v17 = *((_WORD *)a2 + 27) & 3;
      if ( (_DWORD)v17 != 3 )
      {
        result = ipc_log_string(
                   *(_QWORD *)(*a2 + 1696),
                   "%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=Inaccessible, (Unregistered Agent ID)\n",
                   "msm_aer_print_error",
                   *(_DWORD *)(*a2 + 1348),
                   aer_error_severity_string[v17]);
        goto LABEL_71;
      }
    }
    goto LABEL_78;
  }
  v6 = *((unsigned int *)a2 + 13);
  v7 = (a2[7] & 1) == 0;
  v8 = result;
  v9 = v6 & 0x30000;
  if ( (v6 & 0x30000) == 0x20000 )
    v10 = 4544;
  else
    v10 = 16;
  if ( v9 != 0x20000 )
    v7 = 1;
  v11 = (v10 & v3) == 0;
  v12 = 1;
  if ( v11 )
    v12 = 2;
  if ( v7 )
    v13 = v12;
  else
    v13 = 0;
  if ( ((unsigned __int16)v3 & (unsigned __int16)((v9 != 0x20000) << 15)) == 0 )
  {
    if ( v9 == 0x20000 )
      v18 = 0;
    else
      v18 = 1064960;
    if ( (v18 & v3) != 0 )
    {
      v14 = 1;
      v15 = *a2;
      if ( !*a2 )
        goto LABEL_36;
    }
    else
    {
      if ( v9 == 0x20000 )
        v19 = 4352;
      else
        v19 = 0;
      v11 = (v19 & v3) == 0;
      v14 = 3;
      if ( v11 )
        v14 = 0;
      v15 = *a2;
      if ( !*a2 )
        goto LABEL_36;
    }
    goto LABEL_31;
  }
  v14 = 2;
  v15 = *a2;
  if ( *a2 )
  {
LABEL_31:
    v20 = (v6 >> 16) & 3;
    if ( (_DWORD)v20 != 3 )
    {
      v21 = aer_error_layer[v13];
      v22 = aer_agent_string[v14];
      ipc_log_string(
        *(_QWORD *)(v15 + 1704),
        "DBG1:%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=%s, (%s)\n",
        "msm_aer_print_error",
        *(_DWORD *)(v15 + 1348),
        aer_error_severity_string[v20],
        v21,
        v22);
      v23 = *((_WORD *)a2 + 27) & 3;
      if ( (_DWORD)v23 != 3 )
      {
        result = ipc_log_string(
                   *(_QWORD *)(*a2 + 1696),
                   "%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=%s, (%s)\n",
                   "msm_aer_print_error",
                   *(_DWORD *)(*a2 + 1348),
                   aer_error_severity_string[v23],
                   v21,
                   v22);
        if ( *a2 )
        {
          ipc_log_string(
            *(_QWORD *)(*a2 + 1704),
            "DBG1:%s: PCIe: RC%d: device [%04x:%04x] error status/mask=%08x/%08x\n",
            "msm_aer_print_error",
            *(_DWORD *)(*a2 + 1348),
            *(unsigned __int16 *)(v8 + 60),
            *(unsigned __int16 *)(v8 + 62),
            *((_DWORD *)a2 + 14),
            *((_DWORD *)a2 + 15));
          result = ipc_log_string(
                     *(_QWORD *)(*a2 + 1696),
                     "%s: PCIe: RC%d: device [%04x:%04x] error status/mask=%08x/%08x\n",
                     "msm_aer_print_error",
                     *(_DWORD *)(*a2 + 1348),
                     *(unsigned __int16 *)(v8 + 60),
                     *(unsigned __int16 *)(v8 + 62),
                     *((_DWORD *)a2 + 14),
                     *((_DWORD *)a2 + 15));
          if ( *a2 )
          {
            ipc_log_string(
              *(_QWORD *)(*a2 + 1704),
              "DBG1:%s: PCIe: RC%d: device [%04x:%04x] error l1ss_ctl1=%x lnkstat=%x\n",
              "msm_aer_print_error",
              *(_DWORD *)(*a2 + 1348),
              *(unsigned __int16 *)(v8 + 60),
              *(unsigned __int16 *)(v8 + 62),
              *((_DWORD *)a2 + 20),
              *((unsigned __int16 *)a2 + 42));
            result = ipc_log_string(
                       *(_QWORD *)(*a2 + 1696),
                       "%s: PCIe: RC%d: device [%04x:%04x] error l1ss_ctl1=%x lnkstat=%x\n",
                       "msm_aer_print_error",
                       *(_DWORD *)(*a2 + 1348),
                       *(unsigned __int16 *)(v8 + 60),
                       *(unsigned __int16 *)(v8 + 62),
                       *((_DWORD *)a2 + 20),
                       *((unsigned __int16 *)a2 + 42));
          }
        }
        goto LABEL_36;
      }
    }
LABEL_78:
    __break(0x5512u);
  }
LABEL_36:
  v39 = v4;
  v24 = (_DWORD)a2[7] & (unsigned int)~*((_DWORD *)a2 + 15);
  v25 = 0;
  if ( (*((_DWORD *)a2 + 13) & 0x30000) == 0x20000 )
    v26 = &aer_correctable_error_string;
  else
    v26 = &aer_uncorrectable_error_string;
  v38 = v8;
  do
  {
    v27 = (-1LL << v25) & v24;
    if ( !v27 )
      break;
    v28 = __clz(__rbit64(v27));
    if ( *a2 )
    {
      if ( v28 > 0x1F )
      {
        __break(1u);
        goto LABEL_78;
      }
      if ( v26[v28] )
        v29 = v26[v28];
      else
        v29 = "Unknown Error Bit";
      if ( (*((_BYTE *)a2 + 55) & 0x1F) == (_DWORD)v28 )
        v30 = " (First)";
      else
        v30 = (const char *)&unk_24FCB;
      ipc_log_string(
        *(_QWORD *)(*a2 + 1704),
        "DBG1:%s: PCIe: RC%d: [%2d] %-22s%s\n",
        "msm_aer_print_error_stats",
        *(unsigned int *)(*a2 + 1348),
        (unsigned int)v28,
        v29,
        v30);
      if ( (*((_BYTE *)a2 + 55) & 0x1F) == (_DWORD)v28 )
        v31 = " (First)";
      else
        v31 = (const char *)&unk_24FCB;
      result = ipc_log_string(
                 *(_QWORD *)(*a2 + 1696),
                 "%s: PCIe: RC%d: [%2d] %-22s%s\n",
                 "msm_aer_print_error_stats",
                 *(unsigned int *)(*a2 + 1348),
                 (unsigned int)v28,
                 v29,
                 v31);
    }
    v25 = v28 + 1;
  }
  while ( v28 < 0x1F );
  v32 = *(_QWORD **)(v38 + 80);
  v33 = *((_DWORD *)a2 + 13);
  v40[0] = (_DWORD)a2[7] & (unsigned int)~*((_DWORD *)a2 + 15);
  if ( v32 )
  {
    v34 = HIWORD(v33) & 3;
    v4 = v39;
    if ( v34 )
    {
      if ( v34 != 1 )
      {
        if ( v34 == 2 )
        {
          ++v32[70];
          v35 = 16;
        }
        else
        {
          v32 = nullptr;
          v35 = -1;
        }
LABEL_65:
        v36 = v35;
        for ( i = 0; ; i = result + 1 )
        {
          result = find_next_bit(v40, v36, i);
          if ( (int)v36 <= (int)result )
            break;
          ++v32[(int)result];
        }
        if ( (*((_DWORD *)a2 + 13) & 0x80000000) == 0 )
          goto LABEL_71;
        goto LABEL_69;
      }
      ++v32[71];
      v32 += 16;
    }
    else
    {
      ++v32[72];
      v32 += 43;
    }
    v35 = 27;
    goto LABEL_65;
  }
  v4 = v39;
  if ( (v33 & 0x80000000) == 0 )
    goto LABEL_71;
LABEL_69:
  if ( *a2 )
  {
    ipc_log_string(
      *(_QWORD *)(*a2 + 1704),
      "DBG1:%s: PCIe: RC%d: TLP Header: %08x %08x %08x %08x\n",
      "msm_print_tlp_header",
      *(_DWORD *)(*a2 + 1348),
      *((_DWORD *)a2 + 16),
      *((_DWORD *)a2 + 17),
      *((_DWORD *)a2 + 18),
      *((_DWORD *)a2 + 19));
    result = ipc_log_string(
               *(_QWORD *)(*a2 + 1696),
               "%s: PCIe: RC%d: TLP Header: %08x %08x %08x %08x\n",
               "msm_print_tlp_header",
               *(_DWORD *)(*a2 + 1348),
               *((_DWORD *)a2 + 16),
               *((_DWORD *)a2 + 17),
               *((_DWORD *)a2 + 18),
               *((_DWORD *)a2 + 19));
  }
LABEL_71:
  if ( *((_WORD *)a2 + 26) && *((int *)a2 + 12) >= 2 && *((unsigned __int16 *)a2 + 26) == (v4 | (v5 << 8)) && *a2 )
  {
    ipc_log_string(
      *(_QWORD *)(*a2 + 1704),
      "DBG1:%s: PCIe: RC%d: Error of this Agent is reported first\n",
      "msm_aer_print_error",
      *(_DWORD *)(*a2 + 1348));
    result = ipc_log_string(
               *(_QWORD *)(*a2 + 1696),
               "%s: PCIe: RC%d: Error of this Agent is reported first\n",
               "msm_aer_print_error",
               *(_DWORD *)(*a2 + 1348));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
