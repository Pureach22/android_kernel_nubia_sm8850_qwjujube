__int64 __fastcall qcom_glink_ssr_probe(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  __int64 v4; // x9

  v2 = devm_kmalloc(a1, 80, 3520);
  if ( !v2 )
    return 4294967284LL;
  *(_DWORD *)(v2 + 48) = 0;
  v3 = (_QWORD *)v2;
  _init_swait_queue_head(v2 + 56, "&x->wait", &init_completion___key_0);
  v4 = *(_QWORD *)(a1 + 968);
  v3[2] = qcom_glink_ssr_notifier_call;
  *v3 = a1;
  v3[1] = v4;
  *(_QWORD *)(a1 + 152) = v3;
  return blocking_notifier_chain_register(&ssr_notifiers, v3 + 2);
}
