__int64 __fastcall enable_audio_stream(__int64 **a1, unsigned int a2, int a3, int a4)
{
  __int64 v8; // x20
  __int64 v9; // x10
  _BYTE *v10; // x9
  char v11; // w13
  char v12; // w14
  bool v13; // cf
  unsigned int v14; // w9
  int v15; // w10
  __int64 v16; // x8
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  unsigned int v20; // w21
  __int64 result; // x0
  const char *v22; // x4
  int v23; // w8
  _QWORD s[77]; // [xsp+8h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = **a1;
  memset(s, 0, 0x260u);
  *(_QWORD *)((char *)s + 4) = -1;
  v9 = -12;
  *(_QWORD *)((char *)&s[4] + 4) = -1;
  *(_QWORD *)((char *)&s[8] + 4) = -1;
  v10 = (char *)&s[33] + 4;
  s[64] = 0x700000007LL;
  do
  {
    v11 = *v10;
    *((_QWORD *)v10 - 1) = 0xFFFFFFFF00000000LL;
    v12 = v9 + 20;
    v13 = __CFADD__(v9++, 1);
    *v10 = v11 & 0xF0;
    v10 += 12;
    HIDWORD(s[64]) |= 1 << v12;
    LODWORD(s[64]) |= 1 << v12;
  }
  while ( !v13 );
  LODWORD(s[65]) = -1;
  if ( a2 >> 9 > 8 || (v14 = a2 >> 5, a2 >> 5 == 143) )
    __break(1u);
  v15 = *((_DWORD *)&s[4] + v14 + 1);
  *(_QWORD *)((char *)&s[6] + 4) = 0;
  *(_QWORD *)((char *)&s[7] + 4) = 0;
  *(_QWORD *)((char *)&s[4] + 4) = 0;
  *(_QWORD *)((char *)&s[5] + 4) = 0;
  *((_DWORD *)&s[4] + v14 + 1) = v15 & (1 << a2);
  if ( (s[36] & 0x400000000LL) == 0 && ((~BYTE4(s[36]) & 3) != 0 || HIDWORD(s[35]) != LODWORD(s[36])) )
    BYTE4(s[36]) |= 4u;
  LODWORD(s[36]) = a3;
  HIDWORD(s[35]) = a3;
  if ( (s[38] & 4) == 0 && ((~LOBYTE(s[38]) & 3) != 0 || LODWORD(s[37]) != HIDWORD(s[37])) )
    LOBYTE(s[38]) |= 4u;
  HIDWORD(s[37]) = a4;
  LODWORD(s[37]) = a4;
  v16 = *(_QWORD *)(v8 + 24);
  if ( v16 )
  {
    pm_runtime_barrier(v16 + 80);
    snd_usb_autoresume(v8);
    v17 = snd_usb_hw_params(a1, s);
    if ( (v17 & 0x80000000) != 0 )
    {
      v20 = v17;
LABEL_26:
      snd_usb_autosuspend(v8);
      result = v20;
      goto LABEL_27;
    }
    if ( *(_DWORD *)(v8 + 216) )
    {
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: chip already shutdown\n",
        (const char *)&unk_B13E,
        "enable_audio_stream");
      printk("%s%s: chip already shutdown\n", &unk_B45D);
      result = 0;
      goto LABEL_27;
    }
    v18 = snd_usb_lock_shutdown(v8);
    if ( (v18 & 0x80000000) != 0 )
    {
      v20 = v18;
      goto LABEL_25;
    }
    if ( a1[14] && (v19 = snd_usb_endpoint_prepare(v8), (v19 & 0x80000000) != 0)
      || (v19 = snd_usb_endpoint_prepare(v8), (v19 & 0x80000000) != 0) )
    {
      v20 = v19;
      snd_usb_unlock_shutdown(v8);
LABEL_25:
      snd_usb_hw_free(a1);
      goto LABEL_26;
    }
    snd_usb_unlock_shutdown(v8);
    if ( *((_DWORD *)a1 + 6) )
      v22 = "capture";
    else
      v22 = "playback";
    if ( *((_DWORD *)a1[1] + 7) <= 2u )
      v23 = 1000;
    else
      v23 = 125;
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: selected %s iface:%d altsetting:%d datainterval:%dus\n",
      (const char *)&unk_B13E,
      "enable_audio_stream",
      v22,
      *((unsigned __int8 *)a1[4] + 40),
      *((unsigned __int8 *)a1[4] + 41),
      v23 << *((_BYTE *)a1[4] + 52));
    printk("%s%s: selected %s iface:%d altsetting:%d datainterval:%dus\n", &unk_B6EF);
    result = 0;
  }
  else
  {
    result = 4294967277LL;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
