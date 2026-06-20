bool __fastcall sleepmon_is_audio_active(_DWORD *a1)
{
  _BOOL4 v1; // w19
  int v2; // w1
  int v3; // w1
  _DWORD *v5; // x20
  _DWORD *v6; // x20
  _DWORD *v7; // x20
  _DWORD *v8; // x20

  if ( a1[3] && a1[4] )
  {
    v5 = a1;
    v1 = (a1[3] & 0x7F) == 2;
    printk(&unk_9BD7);
    a1 = v5;
    v2 = v5[5];
    if ( !v2 )
      goto LABEL_5;
  }
  else
  {
    v1 = 0;
    v2 = a1[5];
    if ( !v2 )
      goto LABEL_5;
  }
  if ( a1[6] )
  {
    v6 = a1;
    if ( (v2 & 0x7F) == 2 )
      v1 = 1;
    printk(&unk_9BD7);
    a1 = v6;
  }
LABEL_5:
  if ( !a1[7] || !a1[8] )
  {
    v3 = a1[9];
    if ( !v3 )
      goto LABEL_9;
    goto LABEL_8;
  }
  v7 = a1;
  if ( (a1[7] & 0x7F) == 2 )
    v1 = 1;
  printk(&unk_9BD7);
  a1 = v7;
  v3 = v7[9];
  if ( v3 )
  {
LABEL_8:
    if ( a1[10] )
    {
      v8 = a1;
      if ( (v3 & 0x7F) == 2 )
        v1 = 1;
      printk(&unk_9BD7);
      a1 = v8;
    }
  }
LABEL_9:
  if ( a1[11] && a1[12] )
  {
    if ( (a1[11] & 0x7F) == 2 )
      v1 = 1;
    printk(&unk_9BD7);
  }
  return v1;
}
