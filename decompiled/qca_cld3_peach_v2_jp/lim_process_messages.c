_DWORD *__fastcall lim_process_messages(
        _DWORD *result,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v11; // x2
  int v12; // w3
  _DWORD *v13; // x20
  __int64 v14; // x19
  _DWORD *v15; // x20
  _DWORD *v16; // x21
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _DWORD *v51; // x20
  unsigned __int8 v52; // w9
  __int64 v53; // x21
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  _DWORD *v66; // x20
  __int64 v67; // x4
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // [xsp+10h] [xbp-40h] BYREF
  __int64 v85[5]; // [xsp+18h] [xbp-38h] BYREF
  _WORD v86[2]; // [xsp+40h] [xbp-10h] BYREF
  _BYTE v87[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v88; // [xsp+48h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87[0] = 0;
  v86[0] = 0;
  v84 = 0;
  memset(v85, 0, sizeof(v85));
  if ( a2 )
  {
    if ( *result == 1 )
    {
LABEL_3:
      result = *((_DWORD **)a2 + 1);
LABEL_4:
      result = (_DWORD *)_qdf_mem_free((__int64)result);
      *((_QWORD *)a2 + 1) = 0;
      goto LABEL_7;
    }
    v12 = *a2;
    if ( v12 == 5175 || (v12 & 0xFF00) != 0x1400 )
    {
      if ( v12 == 5044 )
      {
LABEL_14:
        switch ( *a2 )
        {
          case 0x116Au:
            lim_process_set_hw_mode_resp(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x116Bu:
          case 0x116Cu:
          case 0x116Du:
          case 0x116Eu:
          case 0x116Fu:
          case 0x1170u:
          case 0x1171u:
          case 0x1172u:
          case 0x1173u:
          case 0x1174u:
          case 0x1175u:
          case 0x1176u:
          case 0x1177u:
          case 0x1178u:
          case 0x1179u:
          case 0x117Au:
          case 0x117Bu:
          case 0x117Cu:
          case 0x117Du:
          case 0x117Eu:
          case 0x117Fu:
          case 0x1180u:
          case 0x1181u:
          case 0x1182u:
          case 0x1183u:
          case 0x1184u:
          case 0x1185u:
          case 0x1186u:
          case 0x1187u:
          case 0x1188u:
          case 0x1189u:
          case 0x118Au:
          case 0x118Bu:
          case 0x118Cu:
          case 0x118Du:
          case 0x118Eu:
          case 0x118Fu:
          case 0x1190u:
          case 0x1191u:
          case 0x1192u:
          case 0x1193u:
          case 0x1194u:
          case 0x1195u:
          case 0x1196u:
          case 0x1197u:
          case 0x1198u:
          case 0x1199u:
          case 0x119Au:
          case 0x119Bu:
          case 0x119Cu:
          case 0x119Du:
          case 0x119Eu:
          case 0x119Fu:
          case 0x11A0u:
          case 0x11A1u:
          case 0x11A2u:
          case 0x11A3u:
          case 0x11A4u:
          case 0x11A5u:
          case 0x11A6u:
          case 0x11A7u:
          case 0x11A8u:
          case 0x11A9u:
          case 0x11ABu:
          case 0x11ACu:
          case 0x11AEu:
          case 0x11AFu:
          case 0x11B0u:
          case 0x11B2u:
          case 0x11B3u:
          case 0x11B4u:
          case 0x11B5u:
          case 0x11B6u:
          case 0x11B7u:
          case 0x11B8u:
          case 0x11B9u:
          case 0x11BAu:
          case 0x11BBu:
          case 0x11BCu:
          case 0x11BDu:
          case 0x11BEu:
          case 0x11C0u:
          case 0x11C1u:
          case 0x11C2u:
          case 0x11C3u:
          case 0x11C4u:
          case 0x11C5u:
          case 0x11C6u:
          case 0x11C7u:
          case 0x11C8u:
          case 0x11C9u:
          case 0x11CAu:
          case 0x11CBu:
          case 0x11CCu:
          case 0x11CDu:
          case 0x11CEu:
          case 0x11CFu:
          case 0x11D0u:
          case 0x11D1u:
          case 0x11D2u:
          case 0x11D3u:
          case 0x11D4u:
          case 0x11D5u:
          case 0x11D6u:
          case 0x11D7u:
          case 0x11D8u:
          case 0x11D9u:
          case 0x11DAu:
          case 0x11DBu:
          case 0x11DCu:
          case 0x11DDu:
          case 0x11DEu:
          case 0x11DFu:
          case 0x11E0u:
          case 0x11E1u:
          case 0x11E2u:
          case 0x11E3u:
          case 0x11E4u:
          case 0x11E5u:
          case 0x11E6u:
          case 0x11E7u:
          case 0x11E8u:
          case 0x11E9u:
          case 0x11EAu:
          case 0x11EBu:
          case 0x11ECu:
          case 0x11EDu:
          case 0x11EEu:
          case 0x11EFu:
          case 0x11F0u:
          case 0x11F1u:
          case 0x11F2u:
          case 0x11F3u:
          case 0x11F4u:
          case 0x11F5u:
          case 0x11F6u:
          case 0x11F7u:
          case 0x11F8u:
          case 0x11F9u:
          case 0x11FAu:
          case 0x11FBu:
          case 0x11FCu:
          case 0x11FDu:
          case 0x11FEu:
          case 0x11FFu:
          case 0x1200u:
          case 0x1201u:
          case 0x1202u:
          case 0x1203u:
          case 0x1204u:
          case 0x1205u:
          case 0x1206u:
          case 0x1207u:
          case 0x1208u:
          case 0x1209u:
          case 0x120Au:
          case 0x120Bu:
          case 0x120Cu:
          case 0x120Du:
          case 0x120Eu:
          case 0x120Fu:
          case 0x1210u:
          case 0x1211u:
          case 0x1212u:
          case 0x1213u:
          case 0x1214u:
          case 0x1215u:
          case 0x1216u:
          case 0x1217u:
          case 0x1218u:
          case 0x1219u:
          case 0x121Au:
          case 0x121Bu:
          case 0x121Cu:
          case 0x121Du:
          case 0x121Eu:
          case 0x121Fu:
          case 0x1220u:
          case 0x1221u:
          case 0x1222u:
          case 0x1223u:
          case 0x1224u:
          case 0x1225u:
          case 0x1226u:
          case 0x1227u:
          case 0x1228u:
          case 0x1229u:
          case 0x122Au:
          case 0x122Bu:
          case 0x122Cu:
          case 0x122Du:
          case 0x122Eu:
          case 0x122Fu:
          case 0x1230u:
          case 0x1231u:
          case 0x1232u:
          case 0x1233u:
          case 0x1234u:
          case 0x1235u:
          case 0x1236u:
          case 0x1237u:
          case 0x1238u:
          case 0x1239u:
          case 0x123Au:
          case 0x123Bu:
          case 0x123Cu:
          case 0x123Du:
          case 0x123Eu:
          case 0x123Fu:
          case 0x1240u:
          case 0x1241u:
          case 0x1242u:
          case 0x1243u:
          case 0x1244u:
          case 0x1245u:
          case 0x1246u:
          case 0x1247u:
          case 0x1248u:
          case 0x1249u:
          case 0x124Au:
          case 0x124Bu:
          case 0x124Cu:
          case 0x124Du:
          case 0x124Eu:
          case 0x124Fu:
          case 0x1250u:
          case 0x1251u:
          case 0x1252u:
          case 0x1253u:
          case 0x1254u:
          case 0x1255u:
          case 0x1256u:
          case 0x1257u:
          case 0x1258u:
          case 0x1259u:
          case 0x125Au:
          case 0x125Bu:
          case 0x125Cu:
          case 0x125Du:
          case 0x125Eu:
          case 0x125Fu:
          case 0x1260u:
          case 0x1261u:
          case 0x1262u:
          case 0x1263u:
          case 0x1264u:
          case 0x1265u:
          case 0x1266u:
          case 0x1267u:
          case 0x1268u:
          case 0x1269u:
          case 0x126Au:
          case 0x126Bu:
          case 0x126Cu:
          case 0x126Du:
          case 0x126Eu:
          case 0x126Fu:
          case 0x1270u:
          case 0x1271u:
          case 0x1272u:
          case 0x1273u:
          case 0x1274u:
          case 0x1275u:
          case 0x1276u:
          case 0x1277u:
          case 0x1278u:
          case 0x1279u:
          case 0x127Au:
          case 0x127Bu:
          case 0x127Cu:
          case 0x127Du:
          case 0x127Eu:
          case 0x127Fu:
          case 0x1280u:
          case 0x1281u:
          case 0x1282u:
          case 0x1283u:
          case 0x1284u:
          case 0x1285u:
          case 0x1286u:
          case 0x1287u:
          case 0x1288u:
          case 0x1289u:
          case 0x128Au:
          case 0x128Bu:
          case 0x128Cu:
          case 0x128Du:
          case 0x128Eu:
          case 0x128Fu:
          case 0x1290u:
          case 0x1291u:
          case 0x1292u:
          case 0x1293u:
          case 0x1294u:
          case 0x1295u:
          case 0x1296u:
          case 0x1297u:
          case 0x1298u:
          case 0x1299u:
          case 0x129Au:
          case 0x129Bu:
          case 0x129Cu:
          case 0x129Du:
          case 0x129Eu:
          case 0x129Fu:
          case 0x12A0u:
          case 0x12A1u:
          case 0x12A2u:
          case 0x12A3u:
          case 0x12A4u:
          case 0x12A5u:
          case 0x12A6u:
          case 0x12A7u:
          case 0x12A8u:
          case 0x12A9u:
          case 0x12AAu:
          case 0x12ABu:
          case 0x12ACu:
          case 0x12ADu:
          case 0x12AEu:
          case 0x12AFu:
          case 0x12B0u:
          case 0x12B1u:
          case 0x12B2u:
          case 0x12B3u:
          case 0x12B4u:
          case 0x12B5u:
          case 0x12B6u:
          case 0x12B7u:
          case 0x12B8u:
          case 0x12B9u:
          case 0x12BAu:
          case 0x12BBu:
          case 0x12BCu:
          case 0x12BDu:
          case 0x12BEu:
          case 0x12BFu:
          case 0x12C0u:
          case 0x12C1u:
          case 0x12C2u:
          case 0x12C3u:
          case 0x12C4u:
          case 0x12C5u:
          case 0x12C6u:
          case 0x12C7u:
          case 0x12C8u:
          case 0x12C9u:
          case 0x12CAu:
          case 0x12CBu:
          case 0x12CCu:
          case 0x12CDu:
          case 0x12CEu:
          case 0x12CFu:
          case 0x12D0u:
          case 0x12D1u:
          case 0x12D2u:
          case 0x12D3u:
          case 0x12D4u:
          case 0x12D5u:
          case 0x12D6u:
          case 0x12D7u:
          case 0x12D8u:
          case 0x12D9u:
          case 0x12DAu:
          case 0x12DBu:
          case 0x12DCu:
          case 0x12DDu:
          case 0x12DEu:
          case 0x12DFu:
          case 0x12E0u:
          case 0x12E1u:
          case 0x12E2u:
          case 0x12E3u:
          case 0x12E4u:
          case 0x12E5u:
          case 0x12E6u:
          case 0x12E7u:
          case 0x12E8u:
          case 0x12E9u:
          case 0x12EAu:
          case 0x12EBu:
          case 0x12ECu:
          case 0x12EDu:
          case 0x12EEu:
          case 0x12EFu:
          case 0x12F0u:
          case 0x12F1u:
          case 0x12F2u:
          case 0x12F3u:
          case 0x12F4u:
          case 0x12F5u:
          case 0x12F6u:
          case 0x12F7u:
          case 0x12F8u:
          case 0x12F9u:
          case 0x12FAu:
          case 0x12FBu:
          case 0x12FCu:
          case 0x12FDu:
          case 0x12FEu:
          case 0x12FFu:
          case 0x1300u:
          case 0x1301u:
          case 0x1302u:
          case 0x1303u:
          case 0x1304u:
          case 0x1305u:
          case 0x1306u:
          case 0x1307u:
          case 0x1308u:
          case 0x1309u:
          case 0x130Au:
          case 0x130Bu:
          case 0x130Cu:
          case 0x130Du:
          case 0x130Eu:
          case 0x130Fu:
          case 0x1310u:
          case 0x1311u:
          case 0x1312u:
          case 0x1313u:
          case 0x1314u:
          case 0x1315u:
          case 0x1316u:
          case 0x1317u:
          case 0x1318u:
          case 0x1319u:
          case 0x131Au:
          case 0x131Bu:
          case 0x131Cu:
          case 0x131Du:
          case 0x131Eu:
          case 0x131Fu:
          case 0x1320u:
          case 0x1321u:
          case 0x1322u:
          case 0x1323u:
          case 0x1324u:
          case 0x1325u:
          case 0x1326u:
          case 0x1327u:
          case 0x1328u:
          case 0x1329u:
          case 0x132Au:
          case 0x132Bu:
          case 0x132Cu:
          case 0x132Du:
          case 0x132Eu:
          case 0x132Fu:
          case 0x1330u:
          case 0x1331u:
          case 0x1332u:
          case 0x1333u:
          case 0x1334u:
          case 0x1335u:
          case 0x1336u:
          case 0x1337u:
          case 0x1338u:
          case 0x1339u:
          case 0x133Au:
          case 0x133Bu:
          case 0x133Cu:
          case 0x133Du:
          case 0x133Eu:
          case 0x133Fu:
          case 0x1340u:
          case 0x1341u:
          case 0x1342u:
          case 0x1343u:
          case 0x1344u:
          case 0x1345u:
          case 0x1346u:
          case 0x1347u:
          case 0x1348u:
          case 0x1349u:
          case 0x134Au:
          case 0x134Bu:
          case 0x134Cu:
          case 0x134Du:
          case 0x134Eu:
          case 0x134Fu:
          case 0x1350u:
          case 0x1351u:
          case 0x1352u:
          case 0x1353u:
          case 0x1354u:
          case 0x1355u:
          case 0x1356u:
          case 0x1357u:
          case 0x1358u:
          case 0x1359u:
          case 0x135Au:
          case 0x135Bu:
          case 0x135Cu:
          case 0x135Du:
          case 0x135Eu:
          case 0x135Fu:
          case 0x1360u:
          case 0x1361u:
          case 0x1362u:
          case 0x1363u:
          case 0x1364u:
          case 0x1365u:
          case 0x1366u:
          case 0x1367u:
          case 0x1368u:
          case 0x1369u:
          case 0x136Au:
          case 0x136Bu:
          case 0x136Cu:
          case 0x136Du:
          case 0x136Eu:
          case 0x136Fu:
          case 0x1370u:
          case 0x1371u:
          case 0x1372u:
          case 0x1373u:
          case 0x1374u:
          case 0x1375u:
          case 0x1376u:
          case 0x1377u:
          case 0x1378u:
          case 0x1379u:
          case 0x137Au:
          case 0x137Bu:
          case 0x137Cu:
          case 0x137Du:
          case 0x137Eu:
          case 0x137Fu:
          case 0x1380u:
          case 0x1381u:
          case 0x1382u:
          case 0x1383u:
          case 0x1384u:
          case 0x1385u:
          case 0x1386u:
          case 0x1387u:
          case 0x1388u:
          case 0x1389u:
          case 0x138Au:
          case 0x138Bu:
          case 0x138Cu:
          case 0x138Du:
          case 0x138Eu:
          case 0x138Fu:
          case 0x1390u:
          case 0x1391u:
          case 0x1392u:
          case 0x1393u:
          case 0x1394u:
          case 0x1395u:
          case 0x1396u:
          case 0x1397u:
          case 0x1398u:
          case 0x1399u:
          case 0x139Au:
          case 0x139Bu:
          case 0x139Cu:
          case 0x139Du:
          case 0x139Eu:
          case 0x139Fu:
          case 0x13A0u:
          case 0x13A1u:
          case 0x13A2u:
          case 0x13A3u:
          case 0x13A4u:
          case 0x13A5u:
          case 0x13A6u:
          case 0x13A7u:
          case 0x13A8u:
          case 0x13A9u:
          case 0x13AAu:
          case 0x13ABu:
          case 0x13ACu:
          case 0x13ADu:
          case 0x13AEu:
          case 0x13AFu:
          case 0x13B0u:
          case 0x13B1u:
          case 0x13B2u:
          case 0x13B3u:
          case 0x13B5u:
          case 0x13B6u:
          case 0x13B7u:
          case 0x13B8u:
          case 0x13B9u:
          case 0x13BAu:
          case 0x13BBu:
          case 0x13BCu:
          case 0x13BDu:
          case 0x13BEu:
          case 0x13BFu:
          case 0x13C0u:
          case 0x13C2u:
          case 0x13C4u:
          case 0x13C6u:
          case 0x13C7u:
          case 0x13C8u:
          case 0x13C9u:
          case 0x13CAu:
          case 0x13CBu:
          case 0x13CCu:
          case 0x13CDu:
          case 0x13CEu:
          case 0x13CFu:
          case 0x13D0u:
          case 0x13D1u:
          case 0x13D8u:
          case 0x13D9u:
          case 0x13DAu:
          case 0x13DBu:
          case 0x13DDu:
          case 0x13DEu:
          case 0x13DFu:
          case 0x13E0u:
          case 0x13E1u:
          case 0x13E2u:
          case 0x13E3u:
          case 0x13E4u:
          case 0x13E5u:
          case 0x13E6u:
          case 0x13E8u:
          case 0x13EAu:
          case 0x13EBu:
          case 0x13ECu:
          case 0x13EDu:
          case 0x13EFu:
          case 0x13F0u:
          case 0x13F1u:
          case 0x13F2u:
          case 0x13F3u:
          case 0x13F5u:
          case 0x13F7u:
          case 0x13F9u:
          case 0x13FAu:
          case 0x13FBu:
          case 0x13FCu:
          case 0x1402u:
          case 0x1403u:
          case 0x1404u:
          case 0x1405u:
          case 0x1406u:
          case 0x1407u:
          case 0x1409u:
          case 0x140Au:
          case 0x140Du:
          case 0x140Eu:
          case 0x140Fu:
          case 0x1410u:
          case 0x1411u:
          case 0x1412u:
          case 0x1414u:
          case 0x1415u:
          case 0x1419u:
          case 0x141Bu:
          case 0x141Du:
          case 0x141Fu:
          case 0x1420u:
          case 0x1423u:
          case 0x1424u:
          case 0x1425u:
          case 0x1426u:
          case 0x1429u:
          case 0x142Au:
          case 0x142Cu:
          case 0x142Du:
          case 0x142Fu:
          case 0x1432u:
          case 0x1433u:
          case 0x1435u:
          case 0x1438u:
          case 0x1439u:
          case 0x143Bu:
          case 0x143Du:
          case 0x143Fu:
          case 0x1440u:
          case 0x1441u:
          case 0x1442u:
          case 0x1443u:
          case 0x1444u:
          case 0x1445u:
          case 0x1446u:
          case 0x1447u:
          case 0x1448u:
          case 0x1449u:
          case 0x144Au:
          case 0x144Bu:
          case 0x144Cu:
          case 0x144Du:
          case 0x144Eu:
          case 0x144Fu:
          case 0x1451u:
          case 0x1452u:
          case 0x1453u:
          case 0x1455u:
          case 0x1458u:
          case 0x1459u:
          case 0x145Au:
          case 0x145Bu:
          case 0x145Cu:
          case 0x145Fu:
          case 0x1461u:
          case 0x1462u:
          case 0x1463u:
          case 0x1464u:
          case 0x1465u:
          case 0x1466u:
          case 0x1467u:
          case 0x1468u:
          case 0x146Au:
          case 0x146Bu:
          case 0x146Du:
          case 0x146Eu:
          case 0x146Fu:
          case 0x1470u:
          case 0x1471u:
          case 0x1472u:
          case 0x1474u:
          case 0x1475u:
          case 0x1478u:
          case 0x147Cu:
          case 0x147Du:
          case 0x1484u:
          case 0x1485u:
          case 0x1486u:
          case 0x1488u:
          case 0x1489u:
          case 0x148Au:
          case 0x148Cu:
          case 0x148Eu:
          case 0x1495u:
          case 0x1497u:
          case 0x1498u:
          case 0x149Au:
          case 0x149Bu:
          case 0x149Du:
          case 0x149Eu:
          case 0x149Fu:
          case 0x14A0u:
          case 0x14A1u:
          case 0x14A3u:
          case 0x14A4u:
          case 0x14A5u:
          case 0x14A6u:
          case 0x14A7u:
          case 0x14A8u:
          case 0x14A9u:
          case 0x14AAu:
          case 0x14B2u:
          case 0x14B3u:
LABEL_83:
            v66 = result;
            _qdf_mem_free(*((_QWORD *)a2 + 1));
            v67 = *a2;
            *((_QWORD *)a2 + 1) = 0;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Discarding unexpected message received %X",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "lim_process_messages",
              v67);
            result = (_DWORD *)lim_print_msg_name(v66, 2, *a2);
            goto LABEL_7;
          case 0x11AAu:
            lim_process_obss_detection_ind(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x11ADu:
            ((void (__fastcall *)(_DWORD *, _QWORD))lim_process_obss_color_collision_info)(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x11B1u:
            lim_send_bcn_rsp(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x11BFu:
            result = (_DWORD *)lim_req_send_delba_ind_process(
                                 (__int64)result,
                                 (__int64)a2,
                                 a3,
                                 a4,
                                 a5,
                                 a6,
                                 a7,
                                 a8,
                                 a9,
                                 a10);
            goto LABEL_7;
          case 0x13B4u:
            if ( !*((_QWORD *)a2 + 1) )
            {
              v11 = "%s: Message bodyptr is Null";
              goto LABEL_6;
            }
            v16 = result;
            qdf_mem_copy(&v84, a2, 0x30u);
            v17 = v85[0];
            cds_pkt_get_packet_length(v85[0], v86, v18, v19, v20, v21, v22, v23, v24, v25);
            if ( !(unsigned int)wma_ds_peek_rx_packet_info(v17, v85) )
            {
              v34 = *(_BYTE *)(v85[0] + 44);
              if ( (v34 & 2) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: roamCandidateInd: %d",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "lim_process_messages",
                  1);
                v34 = *(_BYTE *)(v85[0] + 44);
              }
              if ( (v34 & 1) != 0 )
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: offloadScanLearn: %d",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "lim_process_messages",
                  1);
              lim_handle80211_frames(v16, &v84, v87);
              if ( v87[0] == 1 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Defer Msg type=%x",
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  "lim_process_messages",
                  *a2);
                result = (_DWORD *)lim_defer_msg((__int64)v16, a2);
                if ( !(_DWORD)result )
                  goto LABEL_7;
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Unable to Defer Msg %x",
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  "lim_process_messages",
                  *a2);
                lim_log_session_states(v16);
              }
            }
            lim_decrement_pending_mgmt_count(v16);
            result = (_DWORD *)cds_pkt_return_packet(v17);
            goto LABEL_7;
          case 0x13C1u:
            result = (_DWORD *)lim_delete_sta_context((__int64)result, (__int64)a2, a3, a4, a5, a6, a7, a8, a9, a10);
            goto LABEL_7;
          case 0x13C3u:
            result = (_DWORD *)lim_update_beacon(result);
            goto LABEL_7;
          case 0x13C5u:
            result = (_DWORD *)lim_rx_invalid_peer_process(
                                 (__int64)result,
                                 (__int64)a2,
                                 a3,
                                 a4,
                                 a5,
                                 a6,
                                 a7,
                                 a8,
                                 a9,
                                 a10);
            goto LABEL_7;
          case 0x13D2u:
          case 0x13D3u:
          case 0x13D4u:
          case 0x13D5u:
          case 0x13D6u:
          case 0x13EEu:
          case 0x13F4u:
          case 0x13F6u:
          case 0x13F8u:
          case 0x13FDu:
          case 0x13FEu:
          case 0x1400u:
            result = (_DWORD *)lim_process_mlm_req_messages(result, a2);
            goto LABEL_7;
          case 0x13D7u:
            v14 = *((_QWORD *)a2 + 1);
            if ( v14 )
            {
              v15 = result;
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: SIR_LIM_HEART_BEAT_TIMEOUT, Session %d",
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                "lim_process_messages",
                *(unsigned __int16 *)(v14 + 8));
              *(_BYTE *)(v14 + 292) = 0;
              result = (_DWORD *)lim_handle_heart_beat_timeout_for_session(v15, v14);
              goto LABEL_7;
            }
            v11 = "%s: Can't Process HB TO - bodyptr is Null";
            goto LABEL_6;
          case 0x13DCu:
            result = (_DWORD *)lim_process_sme_req_messages(result, a2);
            goto LABEL_7;
          case 0x13E7u:
            result = (_DWORD *)lim_handle_cnf_wait_timeout((__int64)result, *((_DWORD *)a2 + 1));
            goto LABEL_7;
          case 0x13E9u:
            result = (_DWORD *)lim_handle_update_olbc_cache(result);
            goto LABEL_7;
          case 0x13FFu:
          case 0x14ADu:
          case 0x14AEu:
            goto LABEL_7;
          case 0x1401u:
          case 0x140Bu:
          case 0x1413u:
          case 0x1416u:
          case 0x1417u:
          case 0x1418u:
          case 0x141Au:
          case 0x141Cu:
          case 0x141Eu:
          case 0x1421u:
          case 0x1427u:
          case 0x1428u:
          case 0x142Bu:
          case 0x142Eu:
          case 0x1430u:
          case 0x1434u:
          case 0x1436u:
          case 0x1437u:
          case 0x1450u:
          case 0x1477u:
          case 0x1479u:
          case 0x147Fu:
          case 0x1480u:
          case 0x1491u:
          case 0x1492u:
          case 0x1493u:
          case 0x1496u:
          case 0x14A2u:
          case 0x14B4u:
          case 0x14B6u:
            result = (_DWORD *)lim_process_normal_hdd_msg(result, a2, 0);
            goto LABEL_7;
          case 0x1408u:
          case 0x140Cu:
          case 0x143Au:
          case 0x143Cu:
          case 0x143Eu:
          case 0x1469u:
          case 0x1473u:
          case 0x147Bu:
          case 0x1481u:
          case 0x1482u:
          case 0x148Bu:
            result = (_DWORD *)lim_process_normal_hdd_msg(result, a2, 1);
            goto LABEL_7;
          case 0x1422u:
            lim_reconfig_obss_scan_param(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x1431u:
          case 0x1454u:
          case 0x1456u:
          case 0x1457u:
          case 0x145Du:
          case 0x145Eu:
          case 0x1460u:
          case 0x146Cu:
          case 0x1476u:
          case 0x14B5u:
            lim_process_sme_req_messages(result, a2);
            goto LABEL_3;
          case 0x147Au:
            lim_process_sme_obss_scan_ind(result, a2);
            result = (_DWORD *)_qdf_mem_free(*((_QWORD *)a2 + 1));
            goto LABEL_7;
          case 0x147Eu:
            lim_mon_init_session((__int64)result, *((unsigned __int8 **)a2 + 1));
            goto LABEL_3;
          case 0x1483u:
            lim_process_set_default_scan_ie_request(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x1487u:
            lim_process_sme_del_all_tdls_peers(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x148Du:
            lim_process_set_he_bss_color(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x148Fu:
            lim_send_mgmt_frame_tx(result, a2);
            goto LABEL_3;
          case 0x1490u:
            lim_process_sae_msg((__int64)result, *((_QWORD *)a2 + 1), a3, a4, a5, a6, a7, a8, a9, a10);
            goto LABEL_3;
          case 0x1494u:
            result = (_DWORD *)lim_send_csa_restart_req(result, *((unsigned int *)a2 + 1));
            goto LABEL_7;
          case 0x1499u:
            result = (_DWORD *)lim_continue_sta_csa_req(result, *((unsigned int *)a2 + 1));
            goto LABEL_7;
          case 0x149Cu:
            lim_mon_deinit_session((__int64)result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          case 0x14ABu:
            result = (_DWORD *)cm_process_peer_create(a2);
            goto LABEL_7;
          case 0x14ACu:
            result = (_DWORD *)cm_process_disconnect_req(a2);
            goto LABEL_7;
          case 0x14AFu:
LABEL_21:
            result = (_DWORD *)lim_handle_csa_offload_msg(result, a2);
            goto LABEL_7;
          case 0x14B0u:
            result = (_DWORD *)lim_deactivate_timers_for_vdev(result, *((unsigned int *)a2 + 1));
            goto LABEL_7;
          case 0x14B1u:
            lim_process_pasn_delete_all_peers(result, *((_QWORD *)a2 + 1));
            goto LABEL_3;
          default:
            switch ( *a2 )
            {
              case 0x1022u:
                result = (_DWORD *)lim_process_add_sta_rsp(result, a2);
                goto LABEL_7;
              case 0x1024u:
                result = (_DWORD *)lim_process_mlm_del_sta_rsp(result, a2);
                goto LABEL_7;
              case 0x1028u:
              case 0x104Fu:
                result = (_DWORD *)lim_handle_delete_bss_rsp(result, *((_QWORD *)a2 + 1));
                goto LABEL_7;
              case 0x1033u:
              case 0x105Bu:
                result = (_DWORD *)lim_process_mlm_set_bss_key_rsp(result, a2);
                goto LABEL_7;
              case 0x1035u:
                result = (_DWORD *)lim_process_mlm_set_sta_key_rsp(result, a2);
                goto LABEL_7;
              case 0x1042u:
                lim_ps_offload_handle_missed_beacon_ind((__int64)result, (__int64)a2);
                goto LABEL_3;
              case 0x105Cu:
                result = (_DWORD *)lim_process_hal_add_ts_rsp(
                                     (__int64)result,
                                     (__int64)a2,
                                     a3,
                                     a4,
                                     a5,
                                     a6,
                                     a7,
                                     a8,
                                     a9,
                                     a10);
                goto LABEL_7;
              case 0x1064u:
              case 0x1067u:
                goto LABEL_3;
              case 0x1083u:
                rrm_set_max_tx_power_rsp(result, a2);
                result = *((_DWORD **)a2 + 1);
                if ( result )
                  goto LABEL_4;
                goto LABEL_7;
              case 0x108Eu:
                result = (_DWORD *)lim_process_ft_aggr_qos_rsp(
                                     (__int64)result,
                                     (__int64)a2,
                                     a3,
                                     a4,
                                     a5,
                                     a6,
                                     a7,
                                     a8,
                                     a9,
                                     a10);
                goto LABEL_7;
              case 0x1090u:
                v51 = result;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Received message Noa_ATTR %x",
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  "lim_process_messages",
                  4240);
                if ( !*((_WORD *)v51 + 1996) )
                  goto LABEL_3;
                v52 = 0;
                break;
              case 0x1099u:
                lim_process_set_antenna_resp(result, *((_QWORD *)a2 + 1));
                goto LABEL_3;
              case 0x10A5u:
                result = (_DWORD *)lim_send_sme_pe_ese_tsm_rsp(result, *((_QWORD *)a2 + 1));
                goto LABEL_7;
              case 0x10BBu:
                lim_process_dual_mac_cfg_resp(result, *((_QWORD *)a2 + 1));
                goto LABEL_3;
              case 0x10C9u:
                goto LABEL_21;
              case 0x10D3u:
                lim_process_beacon_tx_success_ind(result, 4307, *((_QWORD *)a2 + 1));
                goto LABEL_3;
              case 0x10DFu:
                result = (_DWORD *)lim_disassoc_tx_complete_cnf(result, *((unsigned int *)a2 + 1), *((_QWORD *)a2 + 1));
                goto LABEL_7;
              case 0x10E0u:
                result = (_DWORD *)lim_deauth_tx_complete_cnf(result, *((unsigned int *)a2 + 1), *((_QWORD *)a2 + 1));
                goto LABEL_7;
              default:
                goto LABEL_83;
            }
            break;
        }
        while ( 1 )
        {
          v53 = *((_QWORD *)v51 + 1533) + 10792LL * v52;
          if ( v53 )
          {
            if ( *(_BYTE *)(v53 + 70) && *(_DWORD *)(v53 + 7036) == 3 )
              break;
          }
          if ( *((unsigned __int16 *)v51 + 1996) <= (unsigned int)++v52 )
            goto LABEL_3;
        }
        qdf_mem_copy((void *)(v53 + 7056), *((const void **)a2 + 1), 0x24u);
        if ( v53 == -24 )
        {
          v64 = 0;
          v62 = 0;
          v63 = 0;
          v65 = 0;
        }
        else
        {
          v62 = *(unsigned __int8 *)(v53 + 24);
          v63 = *(unsigned __int8 *)(v53 + 25);
          v64 = *(unsigned __int8 *)(v53 + 26);
          v65 = *(unsigned __int8 *)(v53 + 29);
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: bssId%02x:%02x:%02x:**:**:%02x ctWin=%d oppPsFlag=%d",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "lim_process_messages",
          v62,
          v63,
          v64,
          v65,
          HIWORD(*(_DWORD *)(v53 + 7056)) & 0x7F,
          (*(_DWORD *)(v53 + 7056) >> 23) & 1,
          v84);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: uNoa1IntervalCnt=%d uNoa1Duration=%d uNoa1Interval=%d uNoa1StartTime=%d",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "lim_process_messages",
          *(unsigned __int8 *)(v53 + 7063),
          *(unsigned int *)(v53 + 7064),
          *(unsigned int *)(v53 + 7068),
          *(unsigned int *)(v53 + 7072));
        goto LABEL_3;
      }
      v13 = result;
      mac_trace_msg_rx(result, 255, *a2);
    }
    else
    {
      v13 = result;
      qdf_trace(53, 7u, 255, v12);
    }
    result = v13;
    goto LABEL_14;
  }
  v11 = "%s: Message pointer is Null";
LABEL_6:
  result = (_DWORD *)qdf_trace_msg(0x35u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_messages");
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
