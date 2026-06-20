__int64 __fastcall msm_dmic_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x20
  const char *v5; // x0
  char *v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x0
  unsigned int active; // w0
  unsigned int v11; // w19
  void *v12; // x0
  unsigned int v14; // w0
  __int64 result; // x0
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 40);
  v5 = *(const char **)(a1 + 8);
  v16 = 0;
  v6 = strpbrk(v5, "01234567");
  if ( !v6 )
  {
    if ( (unsigned int)__ratelimit(&msm_dmic_event__rs, "msm_dmic_event") )
      dev_err(*(_QWORD *)(v4 - 184), "%s: widget not found\n", "msm_dmic_event");
    goto LABEL_22;
  }
  if ( (kstrtouint(v6, 10, &v16) & 0x80000000) != 0 )
  {
    if ( (unsigned int)__ratelimit(&msm_dmic_event__rs_118, "msm_dmic_event") )
      dev_err(*(_QWORD *)(v4 - 184), "%s: Invalid DMIC line on the codec\n", "msm_dmic_event");
    goto LABEL_22;
  }
  if ( v16 >= 8 )
  {
    if ( (unsigned int)__ratelimit(&msm_dmic_event__rs_120, "msm_dmic_event") )
      dev_err(*(_QWORD *)(v4 - 184), "%s: Invalid DMIC Selection\n", "msm_dmic_event");
    goto LABEL_22;
  }
  v7 = *(&off_19E70 + v16);
  v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 - 176) + 784LL) + qword_19E30[v16]);
  if ( a3 == 8 )
  {
    if ( (*v7)-- == 1 )
    {
      v14 = msm_cdc_pinctrl_select_sleep_state(v8);
      if ( (v14 & 0x80000000) != 0 )
      {
        v11 = v14;
        if ( (unsigned int)__ratelimit(&msm_dmic_event__rs_125, "msm_dmic_event") )
        {
          v12 = &unk_132E8;
          goto LABEL_27;
        }
        goto LABEL_25;
      }
    }
    goto LABEL_19;
  }
  if ( a3 != 1 )
  {
    if ( (unsigned int)__ratelimit(&msm_dmic_event__rs_127, "msm_dmic_event") )
      printk(&unk_13653, "msm_dmic_event", a3);
LABEL_22:
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( !(*v7)++ )
  {
    active = msm_cdc_pinctrl_select_active_state(v8);
    if ( (active & 0x80000000) != 0 )
    {
      v11 = active;
      if ( (unsigned int)__ratelimit(&msm_dmic_event__rs_122, "msm_dmic_event") )
      {
        v12 = &unk_1362C;
LABEL_27:
        printk(v12, "msm_dmic_event", "dmic_gpio");
        result = v11;
        goto LABEL_23;
      }
LABEL_25:
      result = v11;
      goto LABEL_23;
    }
  }
LABEL_19:
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
