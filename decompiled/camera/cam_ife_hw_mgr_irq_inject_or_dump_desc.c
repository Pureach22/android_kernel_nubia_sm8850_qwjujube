__int64 __fastcall cam_ife_hw_mgr_irq_inject_or_dump_desc(_QWORD *a1, int *a2, char a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x20
  int v8; // w3
  __int64 *v9; // x8
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 *v12; // x8
  __int64 *v13; // x8
  __int64 *v14; // x8
  __int64 *v15; // x8
  __int64 *v16; // x8
  __int64 *v17; // x8
  __int64 *v18; // x8
  __int64 *v19; // x8
  unsigned int v20; // w21
  __int64 (__fastcall *v21)(__int64, __int64, int *, __int64); // x9
  __int64 v22; // x0
  int v23; // w8
  const char *v24; // x3
  unsigned int v25; // w0
  int v26; // w3
  __int64 v27; // x4
  int v28; // w8
  const char *v29; // x5
  const char *v30; // x5
  int v31; // w8

  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(1500, 0xCC0u, 0, "cam_ife_hw_mgr_irq_inject_or_dump_desc", 0x1DDDu);
  else
    v6 = _kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
  v7 = (_QWORD *)v6;
  if ( !v6 )
    return (unsigned int)-12;
  v8 = *a2;
  *((_QWORD *)a2 + 4) = v6;
  switch ( v8 )
  {
    case 0:
      v10 = a1[12];
      if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
      {
        v10 = a1[13];
        if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
        {
          v10 = a1[14];
          if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
          {
            v10 = a1[15];
            if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
            {
              v10 = a1[16];
              if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
              {
                v10 = a1[17];
                if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
                {
                  v10 = a1[18];
                  if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
                  {
                    v10 = a1[19];
                    if ( !v10 || *(_DWORD *)(v10 + 4) != a2[1] )
                      goto LABEL_30;
                  }
                }
              }
            }
          }
        }
      }
      goto LABEL_47;
    case 2:
      v13 = (__int64 *)a1[20];
      if ( v13 )
      {
        v10 = *v13;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v14 = (__int64 *)a1[21];
      if ( v14 )
      {
        v10 = *v14;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v15 = (__int64 *)a1[22];
      if ( v15 )
      {
        v10 = *v15;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v16 = (__int64 *)a1[23];
      if ( v16 )
      {
        v10 = *v16;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v17 = (__int64 *)a1[24];
      if ( v17 )
      {
        v10 = *v17;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v18 = (__int64 *)a1[25];
      if ( v18 )
      {
        v10 = *v18;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v19 = (__int64 *)a1[26];
      if ( v19 )
      {
        v10 = *v19;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v12 = (__int64 *)a1[27];
      if ( !v12 )
        goto LABEL_30;
LABEL_13:
      v10 = *v12;
      if ( *(_DWORD *)(v10 + 4) != a2[1] )
        goto LABEL_30;
LABEL_29:
      if ( !v10 )
        goto LABEL_30;
LABEL_47:
      v21 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v10 + 88);
      v22 = *(_QWORD *)(v10 + 112);
      if ( (a3 & 1) != 0 )
      {
        if ( *((_DWORD *)v21 - 1) != -1055839300 )
          __break(0x8229u);
        v20 = v21(v22, 78, a2, 40);
        if ( v20 )
        {
          v23 = *a2;
          if ( *a2 )
          {
            if ( v23 == 7 )
            {
              v24 = "SFE";
            }
            else if ( v23 == 2 )
            {
              if ( dword_3A8694 == 65555 )
                v24 = "MC_TFE";
              else
                v24 = "VFE";
            }
            else
            {
              v24 = "Invalid hw_type";
            }
          }
          else
          {
            v24 = "CSID";
          }
          scnprintf(v7, 1500, "Failed to dump irq description for %s\n", v24);
        }
      }
      else
      {
        if ( *((_DWORD *)v21 - 1) != -1055839300 )
          __break(0x8229u);
        v25 = v21(v22, 77, a2, 40);
        v26 = a2[3];
        v27 = *((_QWORD *)a2 + 2);
        v28 = *a2;
        if ( v25 )
        {
          v20 = v25;
          if ( v28 )
          {
            if ( v28 == 7 )
            {
              v29 = "SFE";
            }
            else if ( v28 == 2 )
            {
              if ( dword_3A8694 == 65555 )
                v29 = "MC_TFE";
              else
                v29 = "VFE";
            }
            else
            {
              v29 = "Invalid hw_type";
            }
          }
          else
          {
            v29 = "CSID";
          }
          scnprintf(v7, 1500, "Injecting IRQ %#x failed at req: %lld for %s\n", v26, v27, v29);
        }
        else
        {
          if ( v28 )
          {
            if ( v28 == 7 )
            {
              v30 = "SFE";
            }
            else if ( v28 == 2 )
            {
              if ( dword_3A8694 == 65555 )
                v30 = "MC_TFE";
              else
                v30 = "VFE";
            }
            else
            {
              v30 = "Invalid hw_type";
            }
          }
          else
          {
            v30 = "CSID";
          }
          scnprintf(v7, 1500, "IRQ %#x injected at req: %lld for %s\n", v26, v27, v30);
          v20 = 0;
        }
      }
      if ( irq_inject_display_buf )
        strlcat(irq_inject_display_buf, v7, 4096);
      goto LABEL_87;
    case 7:
      v9 = (__int64 *)a1[28];
      if ( v9 )
      {
        v10 = *v9;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v11 = (__int64 *)a1[29];
      if ( v11 )
      {
        v10 = *v11;
        if ( *(_DWORD *)(v10 + 4) == a2[1] )
          goto LABEL_29;
      }
      v12 = (__int64 *)a1[30];
      if ( !v12 )
      {
LABEL_30:
        scnprintf(v6, 1500, "No hw interface for hw type 0x%x\n", v8);
        v20 = -22;
        goto LABEL_87;
      }
      goto LABEL_13;
  }
  scnprintf(v6, 1500, "No matched HW_TYPE\n");
  v20 = -22;
LABEL_87:
  *((_QWORD *)a2 + 2) = 0;
  *(_QWORD *)a2 = -1;
  *((_QWORD *)a2 + 1) = -1;
  v31 = (unsigned __int8)mem_trace_en;
  *((_BYTE *)a2 + 24) = 0;
  *((_QWORD *)a2 + 4) = 0;
  if ( v31 == 1 )
    cam_mem_trace_free(v7, 0);
  else
    kvfree(v7);
  return v20;
}
