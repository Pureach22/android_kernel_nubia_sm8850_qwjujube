__int64 __fastcall msm_vb2_attach_dmabuf(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 *inst_ref; // x0
  __int64 v9; // x21
  __int64 v10; // x19
  __int64 *buffer; // x0
  __int64 v12; // x4
  __int64 v13; // x1
  _QWORD *v14; // x22
  __int64 *v15; // x20
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x23
  void *v22; // x0
  __int64 v23; // x8
  __int64 (__fastcall *v24)(__int64, __int64, __int64, __int64); // x8
  __int64 v25; // x8
  __int64 *v26; // x21
  const char *v27; // x20
  const char *v28; // x0

  if ( !a1 || !a2 || !a3 || !*(_QWORD *)a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v22 = &unk_83321;
      goto LABEL_32;
    }
    return 0;
  }
  inst_ref = get_inst_ref(g_core, *(__int64 **)(*(_QWORD *)a1 + 72LL));
  if ( inst_ref )
  {
    v9 = inst_ref[40];
    v10 = (__int64)inst_ref;
    buffer = msm_vidc_fetch_buffer((__int64)inst_ref, *(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 8));
    if ( buffer )
    {
      buffer[2] = v10;
      v13 = a3;
      buffer[11] = a3;
      *((_DWORD *)buffer + 10) = a4;
      if ( *(_DWORD *)(v10 + 308) == 2 && *((_DWORD *)buffer + 6) == 2 )
      {
        v14 = (_QWORD *)(v10 + 2584);
        while ( 1 )
        {
          v14 = (_QWORD *)*v14;
          if ( v14 == (_QWORD *)(v10 + 2584) )
            break;
          if ( v14[11] == a3 )
          {
            v15 = buffer;
            print_vidc_buffer(4, (__int64)"low ", (__int64)"attach: found ro buf", v10, (__int64)v14);
            v20 = (__int64)v15;
            v15[13] = v14[13];
            v14[13] = 0;
            goto LABEL_30;
          }
        }
      }
      if ( v9
        && (v23 = *(_QWORD *)(v9 + 6568)) != 0
        && (v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v23 + 24)) != nullptr )
      {
        v20 = (__int64)buffer;
        if ( *((_DWORD *)v24 - 1) != -1477809152 )
          __break(0x8228u);
        v25 = v24(v9, v13, a2, 1);
        buffer = (__int64 *)v20;
        *(_QWORD *)(v20 + 104) = v25;
        if ( v25 )
        {
          print_vidc_buffer(4, (__int64)"low ", (__int64)"attach", v10, v20);
LABEL_30:
          put_inst(v10, v16, v17, v18, v19);
          return v20;
        }
      }
      else
      {
        buffer[13] = 0;
      }
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v26 = buffer;
        v27 = buf_name(*((_DWORD *)buffer + 6));
        v28 = buf_region_name(*((_DWORD *)v26 + 7));
        printk(&unk_8CFD3, "err ", v10 + 340, v27, v28);
      }
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_7F625, "err ", v10 + 340, "msm_vb2_attach_dmabuf", v12);
    }
    msm_vidc_change_state(v10, 5u, (__int64)"msm_vb2_attach_dmabuf");
    v20 = 0;
    goto LABEL_30;
  }
  if ( (msm_vidc_debug & 1) == 0 )
    return 0;
  v22 = &unk_86867;
LABEL_32:
  printk(v22, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_attach_dmabuf");
  return 0;
}
