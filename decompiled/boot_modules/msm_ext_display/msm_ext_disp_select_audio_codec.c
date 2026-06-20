__int64 __fastcall msm_ext_disp_select_audio_codec(__int64 a1, __int64 *a2)
{
  __int64 v3; // x21
  _QWORD *v4; // x8
  _QWORD *i; // x12
  __int64 v6; // x9
  __int64 v7; // x10
  unsigned int v8; // w20
  __int64 v9; // x12
  __int64 v10; // x10
  __int64 v11; // x12
  __int64 v12; // x13
  __int64 v13; // x10
  void *v15; // x0
  int v16; // w9

  if ( !a1 || !a2 )
  {
    v15 = &unk_7309;
LABEL_18:
    printk(v15, "msm_ext_disp_select_audio_codec");
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(a1 + 168);
  if ( !v3 )
  {
    v15 = &unk_705D;
    goto LABEL_18;
  }
  mutex_lock(v3 + 88);
  v4 = *(_QWORD **)(v3 + 40);
  if ( v4 )
  {
    for ( i = *(_QWORD **)(v3 + 72); i != (_QWORD *)(v3 + 72); i = (_QWORD *)*i )
    {
      v6 = *(i - 1);
      if ( *(_DWORD *)v6 == *(_DWORD *)a2
        && *(_DWORD *)(v6 + 8) == *((_DWORD *)a2 + 2)
        && *(_DWORD *)(v6 + 4) == *((_DWORD *)a2 + 1) )
      {
        if ( v6 )
        {
          v7 = *(_QWORD *)(v6 + 56);
          v8 = 0;
          v9 = *(_QWORD *)(v6 + 40);
          v4[1] = *(_QWORD *)(v6 + 48);
          v4[2] = v7;
          *v4 = v9;
          v10 = *(_QWORD *)(v6 + 88);
          v11 = *(_QWORD *)(v6 + 64);
          v12 = *(_QWORD *)(v6 + 72);
          v4[5] = *(_QWORD *)(v6 + 80);
          v4[6] = v10;
          v4[3] = v11;
          v4[4] = v12;
          v13 = *a2;
          *(_DWORD *)(v3 + 32) = *((_DWORD *)a2 + 2);
          *(_QWORD *)(v3 + 24) = v13;
          *(_QWORD *)v3 = *(_QWORD *)(v6 + 96);
          *(_QWORD *)(v3 + 8) = *(_QWORD *)(v6 + 104);
          goto LABEL_14;
        }
        break;
      }
    }
    printk(&unk_70FF, "msm_ext_disp_update_audio_ops");
    v8 = -19;
  }
  else
  {
    printk(&unk_7366, "msm_ext_disp_select_audio_codec");
    v8 = -22;
    *(_BYTE *)(v3 + 136) = 1;
    v16 = *((_DWORD *)a2 + 2);
    *(_QWORD *)(v3 + 24) = *a2;
    *(_DWORD *)(v3 + 32) = v16;
  }
LABEL_14:
  mutex_unlock(v3 + 88);
  return v8;
}
