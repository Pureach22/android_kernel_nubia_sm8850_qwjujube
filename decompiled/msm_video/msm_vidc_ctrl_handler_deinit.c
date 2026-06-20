__int64 __fastcall msm_vidc_ctrl_handler_deinit(__int64 a1)
{
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_803AB, "high", a1 + 340, "msm_vidc_ctrl_handler_deinit", *(unsigned int *)(a1 + 1824));
  v4l2_ctrl_handler_free(a1 + 1424);
  *(_QWORD *)(a1 + 1640) = 0;
  *(_QWORD *)(a1 + 1632) = 0;
  *(_QWORD *)(a1 + 1624) = 0;
  *(_QWORD *)(a1 + 1616) = 0;
  *(_QWORD *)(a1 + 1608) = 0;
  *(_QWORD *)(a1 + 1600) = 0;
  *(_QWORD *)(a1 + 1592) = 0;
  *(_QWORD *)(a1 + 1584) = 0;
  *(_QWORD *)(a1 + 1576) = 0;
  *(_QWORD *)(a1 + 1568) = 0;
  *(_QWORD *)(a1 + 1560) = 0;
  *(_QWORD *)(a1 + 1552) = 0;
  *(_QWORD *)(a1 + 1544) = 0;
  *(_QWORD *)(a1 + 1536) = 0;
  *(_QWORD *)(a1 + 1528) = 0;
  *(_QWORD *)(a1 + 1520) = 0;
  *(_QWORD *)(a1 + 1512) = 0;
  *(_QWORD *)(a1 + 1504) = 0;
  *(_QWORD *)(a1 + 1496) = 0;
  *(_QWORD *)(a1 + 1488) = 0;
  *(_QWORD *)(a1 + 1480) = 0;
  *(_QWORD *)(a1 + 1472) = 0;
  *(_QWORD *)(a1 + 1464) = 0;
  *(_QWORD *)(a1 + 1456) = 0;
  *(_QWORD *)(a1 + 1448) = 0;
  *(_QWORD *)(a1 + 1440) = 0;
  *(_QWORD *)(a1 + 1432) = 0;
  *(_QWORD *)(a1 + 1424) = 0;
  return 0;
}
