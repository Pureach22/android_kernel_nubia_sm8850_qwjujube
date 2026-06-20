__int64 __fastcall cam_ife_csid_hw_deinit_irq(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x1
  _QWORD *v5; // x8
  __int64 v6; // x9
  __int64 v7; // x1
  __int64 v8; // x9
  _QWORD *v9; // x8

  v2 = **(_QWORD **)(a1 + 31136);
  if ( *(_DWORD *)(v2 + 656)
    && (cam_irq_controller_deinit((__int64 *)(a1 + 30984)), *(_DWORD *)(v2 + 656) > 1u)
    && (cam_irq_controller_deinit((__int64 *)(a1 + 30992)), *(_DWORD *)(v2 + 656) >= 3u)
    && (v3 = cam_irq_controller_deinit((__int64 *)(a1 + 31000)), *(_DWORD *)(v2 + 656) > 3u)
    || *(_DWORD *)(v2 + 660)
    && (cam_irq_controller_deinit((__int64 *)(a1 + 31000)), *(_DWORD *)(v2 + 660) > 1u)
    && (cam_irq_controller_deinit((__int64 *)(a1 + 31008)), *(_DWORD *)(v2 + 660) >= 3u)
    && (v3 = cam_irq_controller_deinit((__int64 *)(a1 + 31016)), *(_DWORD *)(v2 + 660) > 3u) )
  {
    __break(0x5512u);
    return cam_ife_csid_ver2_free_res(v3);
  }
  else
  {
    cam_irq_controller_deinit((__int64 *)(a1 + 31112));
    if ( *(_QWORD *)(a1 + 31016) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31016));
    if ( *(_QWORD *)(a1 + 31024) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31024));
    if ( *(_QWORD *)(a1 + 31032) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31032));
    if ( *(_QWORD *)(a1 + 31040) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31040));
    if ( *(_QWORD *)(a1 + 31048) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31048));
    if ( *(_QWORD *)(a1 + 31056) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31056));
    if ( *(_QWORD *)(a1 + 31064) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31064));
    if ( *(_QWORD *)(a1 + 31072) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31072));
    if ( *(_QWORD *)(a1 + 31080) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31080));
    if ( *(_QWORD *)(a1 + 31088) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31088));
    if ( *(_QWORD *)(a1 + 31096) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31096));
    if ( *(_QWORD *)(a1 + 31104) )
      cam_irq_controller_deinit((__int64 *)(a1 + 31104));
    v4 = raw_spin_lock_irqsave(a1 + 30972);
    *(_QWORD *)(a1 + 30952) = a1 + 30952;
    *(_QWORD *)(a1 + 30960) = a1 + 30952;
    v5 = (_QWORD *)(a1 + 16600);
    v6 = 256;
    do
    {
      *v5 = v5;
      --v6;
      v5[1] = v5;
      v5 += 7;
    }
    while ( v6 );
    raw_spin_unlock_irqrestore(a1 + 30972, v4);
    v7 = raw_spin_lock_irqsave(a1 + 30976);
    v8 = 256;
    *(_QWORD *)(a1 + 30936) = a1 + 30936;
    *(_QWORD *)(a1 + 30944) = a1 + 30936;
    v9 = (_QWORD *)(a1 + 2264);
    do
    {
      *v9 = v9;
      --v8;
      v9[1] = v9;
      v9 += 7;
    }
    while ( v8 );
    return raw_spin_unlock_irqrestore(a1 + 30976, v7);
  }
}
