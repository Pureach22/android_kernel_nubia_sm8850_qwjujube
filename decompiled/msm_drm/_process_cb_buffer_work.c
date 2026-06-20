__int64 __fastcall process_cb_buffer_work(__int64 result)
{
  __int64 v1; // x19
  char v2; // w20
  int v3; // w27
  _QWORD *v4; // x25
  _QWORD *v5; // x28
  __int64 avail_buffer; // x0
  __int64 v7; // x24
  __int64 *v8; // x26
  __int64 v9; // x8
  int v10; // w9
  _QWORD *v11; // x10
  int v12; // w8
  _DWORD *v13; // x8
  __int64 v14; // x0
  void *v15; // x0
  _QWORD v16[11]; // [xsp+8h] [xbp-58h] BYREF

  v16[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = *(_QWORD *)(result + 40);
    if ( v1 )
    {
      v2 = 0;
      v3 = 0;
      v4 = nullptr;
      v5 = (_QWORD *)(v1 + 8);
      while ( 1 )
      {
        avail_buffer = get_avail_buffer(v1);
        if ( !avail_buffer )
        {
          result = printk(&unk_25E0A8, "_process_cb_buffer_work");
          goto LABEL_25;
        }
        v7 = avail_buffer;
        v8 = (__int64 *)(avail_buffer + 136);
        result = hfi_core_cmds_rx_buf_get(*(_QWORD *)(v1 + 32), avail_buffer + 136);
        if ( (_DWORD)result )
        {
          *(_DWORD *)(v7 + 64) = 1;
          goto LABEL_25;
        }
        v9 = *v8;
        if ( !*v8 )
          goto LABEL_25;
        v10 = *(_DWORD *)(v9 + 16);
        *(_DWORD *)(v7 + 124) = v10;
        v11 = (_QWORD *)*v5;
        if ( (_QWORD *)*v5 == v5 )
        {
LABEL_11:
          if ( (v2 & 1) == 0 )
          {
            printk(&unk_22DC49, "_process_cb_buffer_work");
            result = release_rx_buffer_fail(v7 + 72, v1);
            goto LABEL_25;
          }
          *(_QWORD *)(v7 + 192) = v7 + 192;
          *(_QWORD *)(v7 + 200) = v7 + 192;
          if ( v4 )
          {
LABEL_15:
            v12 = *(unsigned __int16 *)(v9 + 6);
            *(_QWORD *)(v7 + 208) = v4;
            *(_DWORD *)(v7 + 128) = v12;
            v13 = (_DWORD *)v4[14];
            if ( *(v13 - 1) != -1876328786 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64))v13)(v4, v7 + 72);
            goto LABEL_18;
          }
        }
        else
        {
          while ( v11 )
          {
            v4 = v11;
            if ( *((_DWORD *)v11 + 34) == (unsigned __int8)v10 )
            {
              *(_QWORD *)(v7 + 192) = v7 + 192;
              *(_QWORD *)(v7 + 200) = v7 + 192;
              goto LABEL_15;
            }
            v11 = (_QWORD *)*v11;
            if ( (_QWORD *)*v4 == v5 )
              goto LABEL_11;
          }
          *(_QWORD *)(v7 + 192) = v7 + 192;
          *(_QWORD *)(v7 + 200) = v7 + 192;
        }
        printk(&unk_261B80, "_process_cb_buffer_work");
        v14 = *(_QWORD *)(v1 + 32);
        memset(&v16[1], 0, 72);
        v16[0] = v7 + 136;
        if ( (unsigned int)hfi_core_release_rx_buffer(v14, v16, 1) )
          printk(&unk_24F7AD, "release_rx_buffer_fail");
        v4 = nullptr;
        *(_DWORD *)(*(_QWORD *)(v7 + 216) + 64LL) = 1;
LABEL_18:
        ++v3;
        v2 = 1;
        if ( v3 == 202 )
        {
          v15 = &unk_223CBF;
          goto LABEL_28;
        }
      }
    }
    v15 = &unk_245CD7;
LABEL_28:
    result = printk(v15, "_process_cb_buffer_work");
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
