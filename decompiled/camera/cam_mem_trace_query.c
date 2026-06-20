__int64 __fastcall cam_mem_trace_query(char *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x27
  int v7; // w5
  const char *v8; // x6
  int v9; // w0
  const char *v10; // x5
  char *v11; // x6
  __int64 v12; // x4
  __int64 result; // x0
  char *v14; // [xsp+0h] [xbp-330h]
  __int64 v15; // [xsp+8h] [xbp-328h]
  __int64 v16; // [xsp+10h] [xbp-320h] BYREF
  char s[512]; // [xsp+18h] [xbp-318h] BYREF
  __int64 v18; // [xsp+218h] [xbp-118h] BYREF
  __int64 v19; // [xsp+220h] [xbp-110h]
  __int64 v20; // [xsp+228h] [xbp-108h]
  __int64 v21; // [xsp+230h] [xbp-100h]
  __int64 v22; // [xsp+238h] [xbp-F8h]
  __int64 v23; // [xsp+240h] [xbp-F0h]
  __int64 v24; // [xsp+248h] [xbp-E8h]
  __int64 v25; // [xsp+250h] [xbp-E0h]
  __int64 v26; // [xsp+258h] [xbp-D8h]
  __int64 v27; // [xsp+260h] [xbp-D0h]
  __int64 v28; // [xsp+268h] [xbp-C8h]
  __int64 v29; // [xsp+270h] [xbp-C0h]
  __int64 v30; // [xsp+278h] [xbp-B8h]
  __int64 v31; // [xsp+280h] [xbp-B0h]
  __int64 v32; // [xsp+288h] [xbp-A8h]
  __int64 v33; // [xsp+290h] [xbp-A0h]
  __int64 v34; // [xsp+298h] [xbp-98h]
  __int64 v35; // [xsp+2A0h] [xbp-90h]
  __int64 v36; // [xsp+2A8h] [xbp-88h]
  __int64 v37; // [xsp+2B0h] [xbp-80h]
  __int64 v38; // [xsp+2B8h] [xbp-78h]
  __int64 v39; // [xsp+2C0h] [xbp-70h]
  __int64 v40; // [xsp+2C8h] [xbp-68h]
  __int64 v41; // [xsp+2D0h] [xbp-60h]
  __int64 v42; // [xsp+2D8h] [xbp-58h]
  __int64 v43; // [xsp+2E0h] [xbp-50h]
  __int64 v44; // [xsp+2E8h] [xbp-48h]
  __int64 v45; // [xsp+2F0h] [xbp-40h]
  __int64 v46; // [xsp+2F8h] [xbp-38h]
  __int64 v47; // [xsp+300h] [xbp-30h]
  __int64 v48; // [xsp+308h] [xbp-28h]
  __int64 v49; // [xsp+310h] [xbp-20h]
  _QWORD v50[3]; // [xsp+318h] [xbp-18h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v50[0] = 0;
  v49 = 0;
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v42 = 0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0;
  v35 = 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  v26 = 0;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  memset(s, 0, sizeof(s));
  v2 = ktime_get_with_offset(1);
  v3 = raw_spin_lock_irqsave(&dword_2FDB40);
  v4 = g_trace;
  if ( (__int64 *)g_trace == &g_trace )
  {
    raw_spin_unlock_irqrestore(&dword_2FDB40, v3);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x400000,
               2,
               "cam_mem_trace_query",
               547,
               "Empty memory trace list");
    goto LABEL_26;
  }
  v14 = a1;
  v15 = v3;
  v5 = 1000LL * (_QWORD)a1;
  do
  {
    v6 = (v2 - *(_QWORD *)(v4 + 136)) / 1000000;
    if ( v6 < 0x3E8 )
      scnprintf(v50, 8, "%lldms", (v2 - *(_QWORD *)(v4 + 136)) / 1000000);
    else
      scnprintf(v50, 8, "%llds", v6 / 0x3E8);
    if ( v6 < v5 )
      goto LABEL_4;
    v49 = 0;
    v48 = 0;
    v47 = 0;
    v46 = 0;
    v45 = 0;
    v44 = 0;
    v43 = 0;
    v42 = 0;
    v41 = 0;
    v40 = 0;
    v39 = 0;
    v38 = 0;
    v37 = 0;
    v36 = 0;
    v35 = 0;
    v34 = 0;
    v33 = 0;
    v32 = 0;
    v31 = 0;
    v30 = 0;
    v29 = 0;
    v28 = 0;
    v27 = 0;
    v26 = 0;
    v25 = 0;
    v24 = 0;
    v23 = 0;
    v22 = 0;
    v21 = 0;
    v20 = 0;
    v19 = 0;
    v18 = 0;
    v7 = *(_DWORD *)(v4 + 24);
    if ( v7 > 3263 )
    {
      if ( v7 == 3264 )
      {
        v8 = "(GFP_KERNEL)";
        goto LABEL_19;
      }
      if ( v7 != 1051840 )
        goto LABEL_16;
      v8 = "(GFP_USER)";
    }
    else
    {
      if ( v7 == 1 )
      {
        v8 = "(GFP_DMA)";
        goto LABEL_19;
      }
      if ( v7 != 2080 )
      {
LABEL_16:
        v8 = (const char *)&unk_3E455A;
        goto LABEL_19;
      }
      v8 = "(GFP_ATOMIC)";
    }
LABEL_19:
    v9 = scnprintf(
           &v18,
           256,
           "Mem owner %s, size %lu bytes, flags %#x%s, kept_time %s",
           (const char *)(v4 + 28),
           *(_QWORD *)(v4 + 16),
           v7,
           v8,
           (const char *)v50);
    if ( 512 - v16 < (unsigned __int64)v9 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        3,
        "cam_mem_trace_query",
        569,
        "%s",
        s);
      memset(s, 0, sizeof(s));
      v16 = 0;
    }
    cam_print_to_buffer(s, 512, &v16, 3, 0x400000, "%s", (const char *)&v18);
LABEL_4:
    v4 = *(_QWORD *)v4;
  }
  while ( (__int64 *)v4 != &g_trace );
  raw_spin_unlock_irqrestore(&dword_2FDB40, v15);
  if ( s[0] )
  {
    v10 = "%s";
    v11 = s;
    v12 = 580;
  }
  else
  {
    v11 = v14;
    v10 = "No allocated mem kept >= %llds";
    v12 = 582;
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
             3,
             0x400000,
             3,
             "cam_mem_trace_query",
             v12,
             v10,
             v11);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
