__int64 __fastcall hfi_enc_debugfs_dump_status(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  bool v4; // zf
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x20
  int v9; // w8
  const char *v10; // x1
  __int64 v11; // x0
  __int64 v12; // x2

  if ( !a2 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a2 + 128);
  v4 = v2 == a1;
  result = 4294967274LL;
  if ( v4 )
  {
    if ( a1 )
    {
      if ( v2 )
      {
        v6 = *(_QWORD *)(a1 + 4976);
        if ( v6 )
        {
          v7 = *(_QWORD *)(a1 + 200);
          if ( !v7 )
            return 4294967274LL;
          seq_printf(
            a2,
            "intf:%d    vsync:%8d     underrun:%8d    ",
            *(_DWORD *)(v7 + 672) - 1,
            *(_DWORD *)(v6 + 48),
            0);
          v9 = *(_DWORD *)(v7 + 668);
          if ( v9 <= 1 )
          {
            if ( !v9 )
            {
              v10 = "mode: none\n";
              v11 = a2;
              v12 = 11;
              goto LABEL_24;
            }
            if ( v9 != 1 )
              goto LABEL_23;
            v10 = "mode: command\n";
          }
          else
          {
            if ( v9 != 4 )
            {
              if ( v9 == 3 )
              {
                v10 = "mode: wb block\n";
                v11 = a2;
                v12 = 15;
                goto LABEL_24;
              }
              if ( v9 == 2 )
              {
                v10 = "mode: video\n";
                v11 = a2;
                v12 = 12;
LABEL_24:
                seq_write(v11, v10, v12);
                return 0;
              }
LABEL_23:
              v10 = "mode: ???\n";
              v11 = a2;
              v12 = 10;
              goto LABEL_24;
            }
            v10 = "mode: wb line\n";
          }
          v11 = a2;
          v12 = 14;
          goto LABEL_24;
        }
      }
    }
  }
  return result;
}
