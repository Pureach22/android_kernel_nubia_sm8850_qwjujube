__int64 __fastcall si_object_invoke_ctx_invoke(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w19
  unsigned int v9; // w0
  unsigned int v10; // w20

  v8 = 0;
  while ( 1 )
  {
    v9 = (*(_BYTE *)(a1 + 4) & 1) != 0
       ? qcom_scm_invoke_callback_response(*(_QWORD *)(a1 + 1664), *(_QWORD *)(a1 + 1656), a2, a3, a4)
       : qcom_scm_invoke_smc(
           *(_QWORD *)(a1 + 1616),
           *(_QWORD *)(a1 + 1608),
           *(_QWORD *)(a1 + 1664),
           *(_QWORD *)(a1 + 1656),
           a2,
           a3,
           a4);
    v10 = v9;
    if ( v9 != -16 )
      break;
    msleep(30);
    if ( ++v8 == 200 )
      goto LABEL_10;
  }
  if ( !v9 )
    return v10;
LABEL_10:
  printk(&unk_B666, v10);
  return v10;
}
