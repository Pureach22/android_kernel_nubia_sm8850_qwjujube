__int64 __fastcall get_u_handle_from_si_object(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 result; // x0
  int v4; // w8
  _QWORD *v6; // x21
  __int64 v8; // x0
  __int64 v10; // x20
  int v11; // w0
  const char *v12; // x20
  _QWORD *v14; // x21
  unsigned int unused_fd_flags; // w0
  unsigned int v16; // w19
  const char *v17; // x0
  unsigned __int64 v18; // x20
  unsigned __int64 v24; // x9

  if ( a3 )
    *a3 = 0;
  if ( !a1 )
    goto LABEL_9;
  if ( a1 == 1 )
  {
LABEL_5:
    result = 4294967287LL;
LABEL_10:
    *a2 = -1;
    return result;
  }
  v4 = *(_DWORD *)(a1 + 12);
  switch ( v4 )
  {
    case 1:
      v12 = *(const char **)a1;
      v14 = a2;
      unused_fd_flags = get_unused_fd_flags(2);
      a2 = v14;
      if ( (unused_fd_flags & 0x80000000) != 0 )
        goto LABEL_5;
      v16 = unused_fd_flags;
      if ( v12 )
        v17 = v12;
      else
        v17 = "noname";
      v18 = anon_inode_getfile(v17, &qtee_fops, a1, 2);
      if ( v18 > 0xFFFFFFFFFFFFF000LL )
      {
        put_unused_fd(v16);
        a2 = v14;
        goto LABEL_5;
      }
      fd_install(v16, v18);
      *v14 = v16;
      return 0;
    case 2:
      v6 = a2;
      if ( (unsigned int)is_mem_object() )
      {
        v8 = mem_object_to_dma_buf(a1);
        _X8 = *(unsigned __int64 **)(v8 + 8);
        v10 = v8;
        __asm { PRFM            #0x11, [X8] }
        do
          v24 = __ldxr(_X8);
        while ( __stxr(v24 + 1, _X8) );
        if ( !v24 && (get_file___already_done & 1) == 0 )
        {
          get_file___already_done = 1;
          _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
          __break(0x800u);
        }
        v11 = dma_buf_fd(v10, 0x80000);
        *v6 = v11;
        if ( v11 < 0 )
        {
          dma_buf_put(v10);
          a2 = v6;
          goto LABEL_5;
        }
      }
      else
      {
        *v6 = *(_QWORD *)(a1 + 96);
        if ( a3 )
          *a3 = *(_QWORD *)(a1 + 104);
      }
      put_si_object(a1);
      return 0;
    case 16:
LABEL_9:
      result = 0;
      goto LABEL_10;
    default:
      goto LABEL_5;
  }
}
