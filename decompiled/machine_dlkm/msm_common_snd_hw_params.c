__int64 __fastcall msm_common_snd_hw_params(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x23
  const char *v4; // x22
  __int64 pdata; // x19
  unsigned int mi2s_tdm_auxpcm_intf_index; // w0
  unsigned int v7; // w20
  __int64 v8; // x23
  __int64 v9; // x24
  unsigned int v10; // w20
  size_t v11; // x0
  __int64 v12; // x2
  int v13; // w8
  __int64 v14; // x11
  int v15; // w9
  int v16; // w9
  size_t v17; // x0
  __int64 v18; // x2
  unsigned int v19; // w9
  int v20; // w8
  int v21; // w10
  __int64 v22; // x0
  unsigned int v23; // w0
  void *v25; // x0
  unsigned int v26; // w9
  int v27; // w9
  __int64 v28; // x10
  int v29; // w9
  unsigned int v30; // w0
  const char *v33; // x1
  unsigned int v35; // w9
  unsigned int v41; // w9
  __int64 v42; // [xsp+8h] [xbp-18h] BYREF
  __int64 v43; // [xsp+10h] [xbp-10h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(const char **)(*(_QWORD *)(v3 + 16) + 8LL);
  pdata = msm_common_get_pdata(*(_QWORD *)(v3 + 8));
  mi2s_tdm_auxpcm_intf_index = get_mi2s_tdm_auxpcm_intf_index(v4);
  v42 = 0;
  v43 = 0;
  if ( pdata )
  {
    v7 = mi2s_tdm_auxpcm_intf_index;
    if ( (mi2s_tdm_auxpcm_intf_index & 0x80000000) == 0 )
    {
      v8 = pdata + 48LL * mi2s_tdm_auxpcm_intf_index;
      mutex_lock(v8 + 216);
      v9 = pdata + 4LL * v7;
      if ( *(_DWORD *)(v9 + 584) )
      {
        v10 = 0;
        goto LABEL_42;
      }
      v11 = strlen(v4);
      if ( strnstr(v4, "TDM", v11) )
      {
        if ( v7 < 7 )
        {
          v13 = a2[74];
          v14 = pdata + 4LL * v7;
          v15 = 32 * *(_DWORD *)(pdata + 552) * v13;
          LODWORD(v42) = dword_14508[v7];
          HIDWORD(v42) = v15;
          v43 = *(unsigned int *)(v14 + 652);
          if ( !*(_DWORD *)(v14 + 624) )
            goto LABEL_25;
          if ( v13 > 176399 )
          {
            if ( v13 != 176400 )
            {
              v16 = 352800;
              goto LABEL_19;
            }
          }
          else if ( v13 != 44100 )
          {
            v16 = 88200;
LABEL_19:
            if ( v13 != v16 && v7 != 4 )
            {
LABEL_25:
              v10 = audio_prm_set_lpass_clk_cfg(&v42, 1);
              if ( (v10 & 0x80000000) != 0 )
              {
                v25 = &unk_13367;
LABEL_56:
                printk(v25, "msm_common_snd_hw_params", v10);
                goto LABEL_43;
              }
              goto LABEL_42;
            }
          }
          v22 = *(_QWORD *)(pdata + 616);
          if ( v22 )
          {
            if ( *(_DWORD *)(pdata + 612) || (v23 = digital_cdc_rsc_mgr_hw_vote_enable(v22, 0), (v23 & 0x80000000) == 0) )
            {
              _X8 = (unsigned int *)(pdata + 612);
              __asm { PRFM            #0x11, [X8] }
              do
                v41 = __ldxr(_X8);
              while ( __stxr(v41 + 1, _X8) );
              goto LABEL_25;
            }
            v10 = v23;
            printk(&unk_13B69, "mi2s_tdm_hw_vote_req", v23);
          }
          else
          {
            printk(&unk_128BB, "mi2s_tdm_hw_vote_req", v12);
            v10 = -22;
          }
LABEL_55:
          v25 = &unk_13B69;
          goto LABEL_56;
        }
        v33 = "get_tdm_clk_id";
        goto LABEL_50;
      }
      v17 = strlen(v4);
      if ( !strnstr(v4, "MI2S", v17) )
      {
        printk(&unk_1267C, "msm_common_snd_hw_params", v4);
        v10 = 0;
LABEL_43:
        mutex_unlock(v8 + 216);
        goto LABEL_44;
      }
      if ( v7 >= 7 )
      {
        v33 = "get_mi2s_clk_id";
LABEL_50:
        printk(&unk_12C5D, v33, v7);
        v10 = -22;
        goto LABEL_43;
      }
      v19 = a2[9];
      v20 = a2[74];
      LODWORD(v42) = dword_14524[v7];
      if ( v19 )
      {
        v21 = 0;
      }
      else
      {
        v19 = a2[10];
        if ( !v19 )
          goto LABEL_32;
        v21 = 32;
      }
      v26 = __clz(__rbit32(v19)) | v21;
      if ( v26 <= 0x20 && ((1LL << v26) & 0x100000440LL) != 0 )
      {
        v27 = 32;
        goto LABEL_33;
      }
LABEL_32:
      v27 = 16;
LABEL_33:
      v28 = pdata + 4LL * v7;
      HIDWORD(v42) = 2 * v20 * v27;
      v43 = *(unsigned int *)(v28 + 680);
      if ( !*(_DWORD *)(v28 + 624) )
        goto LABEL_41;
      if ( v20 > 176399 )
      {
        if ( v20 != 176400 )
        {
          v29 = 352800;
          goto LABEL_39;
        }
      }
      else if ( v20 != 44100 )
      {
        v29 = 88200;
LABEL_39:
        if ( v20 != v29 && v7 != 4 )
          goto LABEL_41;
      }
      v30 = mi2s_tdm_hw_vote_req(pdata, 1, v18);
      if ( (v30 & 0x80000000) != 0 )
      {
        v10 = v30;
        goto LABEL_55;
      }
LABEL_41:
      v10 = audio_prm_set_lpass_clk_cfg(&v42, 1);
      if ( (v10 & 0x80000000) != 0 )
      {
        v25 = &unk_1320C;
        goto LABEL_56;
      }
LABEL_42:
      _X8 = (unsigned int *)(v9 + 584);
      __asm { PRFM            #0x11, [X8] }
      do
        v35 = __ldxr(_X8);
      while ( __stxr(v35 + 1, _X8) );
      goto LABEL_43;
    }
    v10 = 0;
  }
  else
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(v3 + 8) + 72LL), "%s: pdata is NULL\n", "msm_common_snd_hw_params");
    v10 = -22;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v10;
}
