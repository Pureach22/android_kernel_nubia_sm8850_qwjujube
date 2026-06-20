__int64 __fastcall qcom_smd_qrtr_send(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20

  if ( *(_DWORD *)(a2 + 116) && !_pskb_pull_tail(a2) )
  {
    v4 = -12;
    goto LABEL_6;
  }
  v4 = rpmsg_send(*(_QWORD *)(a1 + 24), *(_QWORD *)(a2 + 224), *(unsigned int *)(a2 + 112));
  if ( v4 )
  {
LABEL_6:
    sk_skb_reason_drop(0, a2, 2);
    return v4;
  }
  consume_skb(a2);
  return v4;
}
