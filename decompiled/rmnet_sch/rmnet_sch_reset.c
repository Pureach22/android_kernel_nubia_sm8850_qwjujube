__int64 __fastcall rmnet_sch_reset(__int64 a1)
{
  __int64 v2; // x9
  __int64 v3; // x0
  unsigned int v4; // w8
  __int64 v5; // x9
  __int64 v6; // x0
  unsigned int v7; // w8
  __int64 v8; // x9
  __int64 v9; // x0
  unsigned int v10; // w8
  __int64 result; // x0
  __int64 v12; // x9
  unsigned int v13; // w8

  kfree_skb_list_reason(*(_QWORD *)(a1 + 384), 2);
  v2 = *(_QWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 400) = 0;
  *(_QWORD *)(a1 + 384) = 0;
  *(_QWORD *)(a1 + 392) = 0;
  *(_QWORD *)(a1 + 408) = 0x4000000000008LL;
  v3 = *(_QWORD *)(a1 + 424);
  v4 = *(_DWORD *)(*(_QWORD *)v2 + 1112LL) / 0xAu;
  *(_DWORD *)(a1 + 416) = 4 * v4;
  *(_DWORD *)(a1 + 420) = 8 * v4;
  kfree_skb_list_reason(v3, 2);
  v5 = *(_QWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 440) = 0;
  *(_QWORD *)(a1 + 424) = 0;
  *(_QWORD *)(a1 + 432) = 0;
  v6 = *(_QWORD *)(a1 + 464);
  *(_QWORD *)(a1 + 448) = 0x2000000000006LL;
  v7 = 3 * (*(_DWORD *)(*(_QWORD *)v5 + 1112LL) / 0xAu);
  LODWORD(v5) = 6 * (*(_DWORD *)(*(_QWORD *)v5 + 1112LL) / 0xAu);
  *(_DWORD *)(a1 + 456) = v7;
  *(_DWORD *)(a1 + 460) = v5;
  kfree_skb_list_reason(v6, 2);
  v8 = *(_QWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 480) = 0;
  *(_QWORD *)(a1 + 464) = 0;
  *(_QWORD *)(a1 + 472) = 0;
  v9 = *(_QWORD *)(a1 + 504);
  *(_QWORD *)(a1 + 488) = 0x1000000000004LL;
  v10 = *(_DWORD *)(*(_QWORD *)v8 + 1112LL) / 0xAu;
  *(_DWORD *)(a1 + 496) = 2 * v10;
  *(_DWORD *)(a1 + 500) = 4 * v10;
  result = kfree_skb_list_reason(v9, 2);
  v12 = *(_QWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 520) = 0;
  *(_QWORD *)(a1 + 504) = 0;
  *(_QWORD *)(a1 + 512) = 0;
  *(_QWORD *)(a1 + 528) = 0x800000000002LL;
  v13 = *(_DWORD *)(*(_QWORD *)v12 + 1112LL) / 0xAu;
  *(_DWORD *)(a1 + 536) = v13;
  *(_DWORD *)(a1 + 540) = 2 * v13;
  return result;
}
