__int64 __fastcall btfm_slim_write(__int64 a1, unsigned __int16 a2, unsigned int a3, unsigned __int8 a4)
{
  int v4; // w23
  const char *v8; // x2
  int v10; // w24
  __int64 v11; // x21
  __int64 v12; // x0
  int v13; // w23
  __int64 v14; // x0
  int v15; // w23
  unsigned int v16; // w20

  v4 = a4;
  if ( a4 )
    v8 = "PGD";
  else
    v8 = (const char *)&unk_8C9D;
  printk(&unk_8C8A, "btfm_slim_write", v8);
  v10 = a2;
  v11 = a1 + 16;
  mutex_lock(a1 + 1024);
  v12 = a1 + 16;
  if ( v4 )
    v12 = *(_QWORD *)(a1 + 8);
  v13 = slim_writeb(v12, (unsigned int)(v10 + 2048), a3);
  mutex_unlock(a1 + 1024);
  if ( !v13 )
    return 0;
  usleep_range_state(5000, 5100, 2);
  mutex_lock(a1 + 1024);
  v14 = a1 + 16;
  if ( a4 )
    v14 = *(_QWORD *)(a1 + 8);
  v15 = slim_writeb(v14, (unsigned int)(v10 + 2048), a3);
  mutex_unlock(a1 + 1024);
  if ( !v15 )
    return 0;
  usleep_range_state(5000, 5100, 2);
  mutex_lock(a1 + 1024);
  if ( a4 )
    v11 = *(_QWORD *)(a1 + 8);
  v16 = slim_writeb(v11, (unsigned int)(v10 + 2048), a3);
  mutex_unlock(a1 + 1024);
  if ( !v16 )
    return 0;
  usleep_range_state(5000, 5100, 2);
  return v16;
}
