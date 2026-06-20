__int64 __fastcall msm_ext_disp_audio_config(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x19
  void *v4; // x0
  _QWORD *v5; // x8

  if ( !a1 )
  {
    v4 = &unk_71BD;
    goto LABEL_18;
  }
  if ( !a2 || *(_DWORD *)a2 == -1 || *(_DWORD *)(a2 + 4) > 1u || *(int *)(a2 + 8) >= 2 )
  {
    v4 = &unk_6F91;
LABEL_18:
    printk(v4, "msm_ext_disp_validate_and_get");
    goto LABEL_19;
  }
  if ( a3 >= 2 )
  {
    printk(&unk_700C, "msm_ext_disp_validate_and_get");
LABEL_19:
    LODWORD(v3) = -22;
    return (unsigned int)v3;
  }
  v3 = *(_QWORD *)(a1 + 168);
  if ( !v3 )
  {
    v4 = &unk_702A;
    goto LABEL_18;
  }
  if ( v3 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( a3 == 1 )
    {
      LODWORD(v3) = msm_ext_disp_select_audio_codec(a1, (__int64 *)a2);
    }
    else
    {
      mutex_lock(v3 + 88);
      v5 = *(_QWORD **)(v3 + 40);
      if ( v5 )
      {
        v5[5] = 0;
        v5[6] = 0;
        v5[3] = 0;
        v5[4] = 0;
        v5[1] = 0;
        v5[2] = 0;
        *v5 = 0;
      }
      *(_DWORD *)(v3 + 24) = -1;
      mutex_unlock(v3 + 88);
      LODWORD(v3) = 0;
    }
  }
  return (unsigned int)v3;
}
