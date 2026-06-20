__int64 __fastcall msm_vidc_register_video_device(_QWORD *a1, int a2, __int64 a3)
{
  _QWORD *v4; // x23
  __int64 v5; // x8
  _QWORD *v6; // x9
  __int64 v7; // x8
  _QWORD *v8; // x23
  __int64 v9; // x10
  unsigned int v10; // w22
  int v11; // w0
  __int64 v12; // x4
  __int64 v13; // x19
  __int64 v14; // x0
  unsigned __int64 v15; // x0
  __int64 v16; // x4
  int v18; // w19
  unsigned int v19; // w20

  if ( (msm_vidc_debug & 2) != 0 )
  {
    v18 = a2;
    v19 = a3;
    printk(&unk_9181F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_register_video_device");
    a2 = v18;
    a3 = v19;
  }
  v4 = &a1[169 * (a2 != 2)];
  v5 = 813;
  if ( a2 != 2 )
    v5 = 812;
  v6 = (_QWORD *)a1[811];
  v7 = a1[v5];
  *((_DWORD *)v4 + 2) = a2;
  v8 = v4 + 1;
  v8[160] = msm_vidc_release_video_device;
  *((_DWORD *)v8 + 305) = 2;
  v9 = a1[574];
  v8[161] = v7;
  v8[22] = v6;
  v8[139] = a1 + 339;
  *((_DWORD *)v8 + 46) = v9;
  if ( a2 == 2 )
    v10 = 16392;
  else
    v10 = 16391;
  v11 = _video_register_device(v8 + 1, 0, a3, 1, *v6);
  if ( !v11 )
  {
    v14 = a1[817];
    v8[43] = a1;
    v15 = v4l2_m2m_init(v14);
    LODWORD(v13) = v15;
    v8[168] = v15;
    if ( v15 < 0xFFFFFFFFFFFFF001LL )
    {
      LODWORD(v13) = v4l2_m2m_register_media_controller(v15, v8 + 1, v10);
      if ( !(_DWORD)v13 )
        return (unsigned int)v13;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8DAB2, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_register_video_device");
      v4l2_m2m_release(v8[168]);
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_81712, "err ", 0xFFFFFFFFLL, "codec", v16);
      v13 = v8[168];
    }
    video_unregister_device(v8 + 1);
    return (unsigned int)v13;
  }
  LODWORD(v13) = v11;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_94BE2, "err ", 0xFFFFFFFFLL, "codec", v12);
  return (unsigned int)v13;
}
