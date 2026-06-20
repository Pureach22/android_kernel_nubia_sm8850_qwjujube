__int64 __fastcall rpmh_invalidate(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( (rpmh_standalone & 1) == 0 )
  {
    v1 = *(_QWORD *)(*(_QWORD *)(result + 96) + 152LL);
    v2 = raw_spin_lock_irqsave(v1 + 1152);
    *(_QWORD *)(v1 + 1168) = 0;
    *(_QWORD *)(v1 + 1176) = 0;
    *(_QWORD *)(v1 + 1184) = 0;
    *(_QWORD *)(v1 + 1192) = 0;
    *(_QWORD *)(v1 + 1200) = 0;
    *(_QWORD *)(v1 + 1208) = 0;
    *(_QWORD *)(v1 + 1216) = 0;
    *(_QWORD *)(v1 + 1224) = 0;
    *(_QWORD *)(v1 + 1232) = 0;
    *(_QWORD *)(v1 + 1240) = 0;
    *(_QWORD *)(v1 + 1248) = 0;
    *(_QWORD *)(v1 + 1256) = 0;
    *(_QWORD *)(v1 + 1264) = 0;
    *(_QWORD *)(v1 + 1272) = 0;
    *(_QWORD *)(v1 + 1280) = 0;
    *(_QWORD *)(v1 + 1288) = 0;
    *(_QWORD *)(v1 + 1296) = 0;
    *(_QWORD *)(v1 + 1304) = 0;
    *(_QWORD *)(v1 + 1312) = 0;
    *(_QWORD *)(v1 + 1320) = 0;
    *(_QWORD *)(v1 + 1328) = 0;
    *(_QWORD *)(v1 + 1336) = 0;
    *(_QWORD *)(v1 + 1344) = 0;
    *(_QWORD *)(v1 + 1352) = 0;
    *(_QWORD *)(v1 + 1360) = 0;
    *(_QWORD *)(v1 + 1368) = 0;
    *(_QWORD *)(v1 + 1376) = 0;
    *(_QWORD *)(v1 + 1384) = 0;
    *(_QWORD *)(v1 + 1392) = 0;
    *(_QWORD *)(v1 + 1624) = 0;
    *(_QWORD *)(v1 + 1616) = 0;
    *(_QWORD *)(v1 + 1608) = 0;
    *(_QWORD *)(v1 + 1600) = 0;
    *(_QWORD *)(v1 + 1592) = 0;
    *(_QWORD *)(v1 + 1584) = 0;
    *(_QWORD *)(v1 + 1576) = 0;
    *(_QWORD *)(v1 + 1568) = 0;
    *(_QWORD *)(v1 + 1560) = 0;
    *(_QWORD *)(v1 + 1552) = 0;
    *(_QWORD *)(v1 + 1544) = 0;
    *(_QWORD *)(v1 + 1536) = 0;
    *(_QWORD *)(v1 + 1528) = 0;
    *(_QWORD *)(v1 + 1520) = 0;
    *(_QWORD *)(v1 + 1512) = 0;
    *(_QWORD *)(v1 + 1504) = 0;
    *(_QWORD *)(v1 + 1496) = 0;
    *(_QWORD *)(v1 + 1488) = 0;
    *(_QWORD *)(v1 + 1480) = 0;
    *(_QWORD *)(v1 + 1472) = 0;
    *(_QWORD *)(v1 + 1464) = 0;
    *(_QWORD *)(v1 + 1456) = 0;
    *(_QWORD *)(v1 + 1448) = 0;
    *(_QWORD *)(v1 + 1440) = 0;
    *(_QWORD *)(v1 + 1432) = 0;
    *(_QWORD *)(v1 + 1424) = 0;
    *(_QWORD *)(v1 + 1416) = 0;
    *(_QWORD *)(v1 + 1408) = 0;
    *(_QWORD *)(v1 + 1400) = 0;
    *(_BYTE *)(v1 + 1156) = 1;
    return raw_spin_unlock_irqrestore(v1 + 1152, v2);
  }
  return result;
}
