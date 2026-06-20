__int64 __fastcall qcom_ddump_gh_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 216);
  v4 = *(_QWORD *)(a2 + 152);
  v7 = 1;
  gh_dbl_read_and_clean(v3, &v7, 0x100000000LL);
  if ( *(_BYTE *)(a2 + 180) != 1 )
  {
    pm_wakeup_ws_event(*(_QWORD *)(a2 + 256), 2000, 1);
    v6 = *(_QWORD *)(a2 + 208);
    v8[0] = 1;
    result = gh_dbl_send(v6, v8, 0);
    if ( (_DWORD)result )
    {
      result = dev_err(*(_QWORD *)a2, "failed to raise virq to the sender %d\n", result);
      if ( *(_QWORD *)(v4 + 8) )
        goto LABEL_6;
    }
    else if ( *(_QWORD *)(v4 + 8) )
    {
      goto LABEL_6;
    }
    result = pm_wakeup_ws_event(*(_QWORD *)(a2 + 256), 0, 1);
    goto LABEL_6;
  }
  result = complete(a2 + 224);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
