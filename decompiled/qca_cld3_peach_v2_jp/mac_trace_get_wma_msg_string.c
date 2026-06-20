const char *__fastcall mac_trace_get_wma_msg_string(unsigned __int16 a1)
{
  int v1; // w9
  int v2; // w8
  const char *result; // x0

  v1 = a1;
  v2 = a1 - 4129;
  result = "WMA_ADD_STA_REQ";
  switch ( v2 )
  {
    case 0:
      return result;
    case 1:
      result = "WMA_ADD_STA_RSP";
      break;
    case 2:
      result = "WMA_DELETE_STA_REQ";
      break;
    case 3:
      result = "WMA_DELETE_STA_RSP";
      break;
    case 4:
      result = "WMA_ADD_BSS_REQ";
      break;
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    case 19:
    case 23:
    case 24:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 34:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 94:
    case 95:
    case 96:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 135:
    case 136:
    case 137:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 149:
    case 150:
    case 154:
    case 155:
    case 156:
    case 157:
    case 161:
    case 163:
    case 164:
    case 165:
    case 167:
    case 169:
    case 170:
    case 173:
    case 175:
    case 176:
    case 177:
    case 179:
    case 180:
    case 181:
    case 182:
    case 183:
    case 194:
    case 195:
    case 196:
    case 197:
    case 198:
    case 199:
    case 200:
    case 201:
    case 202:
    case 203:
    case 204:
    case 210:
    case 211:
    case 212:
    case 214:
    case 216:
    case 217:
    case 218:
    case 221:
    case 222:
    case 223:
    case 224:
    case 225:
    case 226:
    case 227:
    case 230:
    case 233:
    case 234:
    case 235:
    case 239:
    case 240:
    case 241:
    case 242:
    case 243:
    case 244:
    case 245:
    case 246:
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
    case 252:
    case 253:
    case 254:
    case 255:
    case 256:
    case 257:
    case 258:
    case 259:
    case 260:
    case 261:
    case 262:
    case 263:
    case 264:
    case 265:
    case 266:
    case 267:
    case 268:
    case 269:
    case 270:
    case 271:
    case 272:
    case 273:
    case 274:
    case 275:
    case 276:
    case 277:
    case 278:
    case 279:
    case 280:
    case 281:
    case 282:
    case 283:
    case 284:
    case 285:
    case 286:
    case 287:
    case 288:
    case 289:
    case 290:
    case 291:
    case 292:
    case 293:
    case 294:
    case 295:
    case 296:
    case 297:
    case 298:
    case 299:
    case 300:
    case 301:
    case 302:
    case 303:
    case 304:
    case 305:
    case 306:
    case 307:
    case 308:
    case 309:
    case 310:
    case 311:
    case 312:
    case 313:
    case 314:
    case 315:
    case 316:
    case 317:
    case 318:
    case 319:
    case 320:
    case 321:
    case 322:
    case 323:
    case 324:
    case 325:
    case 326:
    case 329:
    case 330:
    case 331:
    case 334:
    case 335:
    case 341:
    case 345:
    case 346:
    case 347:
    case 348:
    case 349:
    case 350:
    case 351:
    case 352:
    case 353:
    case 354:
    case 355:
    case 356:
    case 357:
    case 358:
    case 360:
    case 361:
    case 363:
    case 364:
    case 365:
    case 366:
    case 369:
    case 370:
    case 371:
    case 373:
    case 374:
    case 375:
    case 376:
    case 377:
    case 379:
    case 380:
    case 381:
    case 382:
    case 383:
    case 384:
    case 385:
    case 386:
    case 387:
    case 388:
    case 389:
    case 390:
    case 391:
    case 392:
    case 393:
    case 394:
    case 395:
    case 396:
    case 397:
    case 399:
    case 400:
    case 401:
    case 402:
    case 403:
    case 404:
    case 405:
    case 406:
    case 407:
    case 410:
    case 411:
    case 412:
    case 413:
    case 414:
    case 415:
    case 420:
    case 422:
    case 426:
    case 427:
    case 428:
    case 429:
    case 430:
    case 431:
    case 432:
    case 433:
    case 434:
    case 435:
    case 436:
    case 437:
    case 438:
    case 439:
    case 440:
    case 441:
    case 442:
    case 443:
    case 444:
    case 445:
    case 446:
    case 447:
    case 448:
    case 449:
    case 450:
    case 451:
    case 452:
    case 453:
    case 454:
    case 455:
    case 456:
    case 457:
    case 458:
    case 459:
    case 460:
    case 461:
    case 462:
    case 463:
    case 464:
    case 465:
    case 466:
    case 467:
    case 468:
    case 469:
    case 470:
    case 471:
    case 472:
    case 473:
    case 474:
    case 475:
    case 476:
    case 477:
      goto LABEL_5;
    case 6:
      result = "WMA_DELETE_BSS_REQ";
      break;
    case 7:
      result = "WMA_DELETE_BSS_RSP";
      break;
    case 16:
      result = "WMA_SEND_BEACON_REQ";
      break;
    case 18:
      result = "WMA_SET_BSSKEY_RSP";
      break;
    case 20:
      result = "WMA_SET_STAKEY_RSP";
      break;
    case 21:
      result = "WMA_UPDATE_EDCA_PROFILE_IND";
      break;
    case 22:
      result = "WMA_UPDATE_BEACON_IND";
      break;
    case 25:
      result = "WMA_ADD_TS_REQ";
      break;
    case 26:
      result = "WMA_DEL_TS_REQ";
      break;
    case 33:
      result = "WMA_MISSED_BEACON_IND";
      break;
    case 35:
      result = "WMA_PWR_SAVE_CFG";
      break;
    case 45:
      result = "WMA_DELETE_BSS_HO_FAIL_REQ";
      break;
    case 46:
      result = "WMA_DELETE_BSS_HO_FAIL_RSP";
      break;
    case 58:
      result = "WMA_SET_STA_BCASTKEY_RSP";
      break;
    case 59:
      result = "WMA_ADD_TS_RSP";
      break;
    case 66:
      result = "WMA_SET_MIMOPS_REQ";
      break;
    case 67:
      result = "WMA_SET_MIMOPS_RSP";
      break;
    case 68:
      result = "WMA_SYS_READY_IND";
      break;
    case 69:
      result = "WMA_SET_TX_POWER_REQ";
      break;
    case 70:
      result = "WMA_SET_TX_POWER_RSP";
      break;
    case 93:
      result = "WMA_SEND_PROBE_RSP_TMPL";
      break;
    case 97:
      result = "WMA_SET_MAX_TX_POWER_REQ";
      break;
    case 98:
      result = "WMA_SET_MAX_TX_POWER_RSP";
      break;
    case 108:
      result = "WMA_AGGR_QOS_REQ";
      break;
    case 109:
      result = "WMA_AGGR_QOS_RSP";
      break;
    case 116:
      result = "WMA_SET_KEEP_ALIVE";
      break;
    case 122:
      result = "WMA_8023_MULTICAST_LIST_REQ";
      break;
    case 131:
      result = "WMA_TSM_STATS_REQ";
      break;
    case 132:
      result = "WMA_TSM_STATS_RSP";
      break;
    case 133:
      result = "WMA_SET_TM_LEVEL_REQ";
      break;
    case 134:
      result = "WMA_UPDATE_OP_MODE";
      break;
    case 138:
      result = "WMA_ROAM_PRE_AUTH_STATUS";
      break;
    case 147:
      result = "WMA_DHCP_START_IND";
      break;
    case 148:
      result = "WMA_DHCP_STOP_IND";
      break;
    case 151:
      result = "WMA_ADD_PERIODIC_TX_PTRN_IND";
      break;
    case 152:
      result = "WMA_DEL_PERIODIC_TX_PTRN_IND";
      break;
    case 153:
      result = "SIR_HAL_PDEV_DUAL_MAC_CFG_REQ";
      break;
    case 158:
      result = "WMA_RATE_UPDATE_IND";
      break;
    case 159:
      result = "SIR_HAL_FLUSH_LOG_TO_FW";
      break;
    case 160:
      result = "SIR_HAL_SET_PCL_TO_FW";
      break;
    case 162:
      result = "WMA_CLI_SET_CMD";
      break;
    case 166:
      result = "WMA_UPDATE_CHAN_LIST_REQ";
      break;
    case 168:
      result = "WMA_CSA_OFFLOAD_EVENT";
      break;
    case 171:
      result = "WMA_UPDATE_MEMBERSHIP";
      break;
    case 172:
      result = "WMA_UPDATE_USERPOS";
      break;
    case 174:
      result = "WMA_UPDATE_TDLS_PEER_STATE";
      break;
    case 178:
      result = "WMA_DFS_BEACON_TX_SUCCESS_IND";
      break;
    case 184:
      result = "WMA_INIT_THERMAL_INFO_CMD";
      break;
    case 185:
      result = "WMA_SET_THERMAL_LEVEL";
      break;
    case 186:
      result = "WMA_SET_PLM_REQ";
      break;
    case 187:
      result = "WMA_TX_POWER_LIMIT";
      break;
    case 188:
      result = "WMA_SET_SAP_INTRABSS_DIS";
      break;
    case 189:
      result = "WMA_MODEM_POWER_STATE_IND";
      break;
    case 190:
      result = "WMA_DISASSOC_TX_COMP";
      break;
    case 191:
      result = "WMA_DEAUTH_TX_COMP";
      break;
    case 192:
      result = "WMA_UPDATE_RX_NSS";
      break;
    case 193:
      result = "WMA_STATS_EXT_REQUEST";
      break;
    case 205:
      result = "WMA_CH_AVOID_UPDATE_REQ";
      break;
    case 206:
      result = "WMA_LINK_LAYER_STATS_CLEAR_REQ";
      break;
    case 207:
      result = "WMA_LINK_LAYER_STATS_SET_REQ";
      break;
    case 208:
      result = "WMA_LINK_LAYER_STATS_GET_REQ";
      break;
    case 209:
      result = "WMA_LINK_LAYER_STATS_RESULTS_RSP";
      break;
    case 213:
      result = "SIR_HAL_SET_BASE_MACADDR_IND";
      break;
    case 215:
      result = "WMA_LINK_STATUS_GET_REQ";
      break;
    case 219:
      result = "WMA_GET_TEMPERATURE_REQ";
      break;
    case 220:
      result = "WMA_SET_SCAN_MAC_OUI_REQ";
      break;
    case 228:
      result = "SIR_HAL_SET_MAS";
      break;
    case 229:
      result = "SIR_HAL_SET_MIRACAST";
      break;
    case 231:
      result = "SIR_HAL_CONFIG_STATS_FACTOR";
      break;
    case 232:
      result = "SIR_HAL_CONFIG_GUARD_TIME";
      break;
    case 236:
      result = "WMA_ENABLE_UAPSD_REQ";
      break;
    case 237:
      result = "WMA_DISABLE_UAPSD_REQ";
      break;
    case 238:
      result = "WMA_GW_PARAM_UPDATE_REQ";
      break;
    case 327:
      result = "SIR_HAL_START_STOP_LOGGING";
      break;
    case 328:
      result = "SIR_HAL_PDEV_SET_HW_MODE";
      break;
    case 332:
      result = "WMA_SET_RSSI_MONITOR_REQ";
      break;
    case 333:
      result = "WMA_SET_IE_INFO";
      break;
    case 336:
      result = "WMA_HT40_OBSS_SCAN_IND";
      break;
    case 337:
      result = "WMA_TSF_GPIO_PIN";
      break;
    case 338:
      result = "WMA_ADD_BCN_FILTER_CMDID";
      break;
    case 339:
      result = "WMA_REMOVE_BCN_FILTER_CMDID";
      break;
    case 340:
      result = "WDA_APF_GET_CAPABILITIES_REQ";
      break;
    case 342:
      result = "WMA_SET_WISA_PARAMS";
      break;
    case 343:
      result = "WMA_SET_ADAPT_DWELLTIME_CONF_PARAMS";
      break;
    case 344:
      result = "WMA_SET_PDEV_IE_REQ";
      break;
    case 359:
      result = "WMA_SEND_FREQ_RANGE_CONTROL_IND";
      break;
    case 362:
      result = "WMA_SET_DTIM_PERIOD";
      break;
    case 367:
      result = "WMA_POWER_DEBUG_STATS_REQ";
      break;
    case 368:
      result = "WMA_SET_WOW_PULSE_CMD";
      break;
    case 372:
      result = "WMA_GET_RCPI_REQ";
      break;
    case 378:
      result = "WMA_SET_DBS_SCAN_SEL_CONF_PARAMS";
      break;
    case 398:
      result = "WMA_GET_ROAM_SCAN_STATS";
      break;
    case 408:
      result = "WMA_SET_THERMAL_THROTTLE_CFG";
      break;
    case 409:
      result = "WMA_SET_THERMAL_MGMT";
      break;
    case 416:
      result = "WMA_TWT_ADD_DIALOG_REQUEST";
      break;
    case 417:
      result = "WMA_TWT_DEL_DIALOG_REQUEST";
      break;
    case 418:
      result = "WMA_TWT_PAUSE_DIALOG_REQUEST";
      break;
    case 419:
      result = "WMA_TWT_RESUME_DIALOG_REQUEST";
      break;
    case 421:
      result = "WMA_TWT_NUDGE_DIALOG_REQUEST";
      break;
    case 423:
      result = "WMA_UPDATE_EDCA_PIFS_PARAM_IND";
      break;
    case 424:
      result = "WMA_ENABLE_ACTIVE_APF_MODE_IND";
      break;
    case 425:
      result = "WMA_DISABLE_ACTIVE_APF_MODE_IND";
      break;
    case 478:
      result = "WMA_MSG_TYPES_END";
      break;
    default:
      if ( v1 == 8 )
        result = "WMA_PEER_CREATE_RESPONSE";
      else
LABEL_5:
        result = "UNKNOWN";
      break;
  }
  return result;
}
