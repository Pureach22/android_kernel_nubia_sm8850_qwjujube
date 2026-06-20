__int64 __fastcall uaudio_put_iova(__int64 a1, unsigned __int64 a2, _QWORD *a3, __int64 *a4)
{
  _QWORD *v4; // x8
  const char *v5; // x20
  void *v6; // x1
  const char *v7; // x0
  char v9; // w10
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x10
  bool v12; // cf
  unsigned __int64 v13; // x10
  __int64 v14; // x4

  v4 = (_QWORD *)*a3;
  if ( (_QWORD *)*a3 != a3 )
  {
    v9 = 0;
    v10 = a2;
    while ( 1 )
    {
      if ( v4[2] == a1 )
      {
LABEL_12:
        if ( (v4[4] & 1) == 0 )
        {
          v5 = "%s%s: va %lu is not in use\n";
          ipc_log_string(*(_QWORD *)(uaudio_svc + 24), "%s%s: va %lu is not in use\n", &unk_B13E, "uaudio_put_iova", a1);
          goto LABEL_3;
        }
        v11 = v4[3];
        *((_BYTE *)v4 + 32) = 0;
        if ( v11 == a2 )
          goto LABEL_17;
      }
      else
      {
        if ( (v9 & 1) == 0 )
        {
          while ( 1 )
          {
            v4 = (_QWORD *)*v4;
            if ( v4 == a3 )
              goto LABEL_2;
            if ( v4[2] == a1 )
              goto LABEL_12;
          }
        }
        v11 = v4[3];
      }
      v12 = v10 >= v11;
      v13 = v10 - v11;
      if ( !v12 || (v10 = v13, *((_BYTE *)v4 + 32) = 0, v13) )
      {
        v4 = (_QWORD *)*v4;
        v9 = 1;
        if ( v4 != a3 )
          continue;
      }
LABEL_17:
      v14 = *a4 + a2;
      *a4 = v14;
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: curr_iova_size %zu\n",
        (const char *)&unk_B13E,
        "uaudio_put_iova",
        v14);
      v6 = &unk_B8A7;
      v7 = "%s%s: curr_iova_size %zu\n";
      return printk(v7, v6);
    }
  }
LABEL_2:
  v5 = "%s%s: unable to find the va %lu\n";
  ipc_log_string(*(_QWORD *)(uaudio_svc + 24), "%s%s: unable to find the va %lu\n", &unk_B13E, "uaudio_put_iova", a1);
LABEL_3:
  v6 = &unk_B45D;
  v7 = v5;
  return printk(v7, v6);
}
